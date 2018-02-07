/*
 * LE truc important à noter dans cet exercice est qu'AUCUN read() ou write()
 * potentiellement bloquant n'est effectué sans que select() ne donne son feu
 * vert avant. C'est le seul moyen de garantir qu'on ne va pas aboutir à
 * un interbloquage.
 *
 *
 *
 * Les offsets off_pong et off_ping sont là pour que le code soit correct
 * même si les read() et les write() pouvaient être partiels.
 *
 * Cependant, vu qu'on écrit dans des tubes et que "ping" et "pong" sont
 * sans doute nettement plus petits que PIPE_BUF (qui est la limite en-dessous
 * de laquelle une écriture dans un tube est atomique), une implémentation sans
 * ces offsets fonctionnera et sera relativement plus simple.
 *
 * Si des étudiants le font, vous pouvez leur faire créer un buffer de plus
 * de PIPE_BUF octets (pour info sur tanit, c'est 5120 octets) pour "ping" et
 * "pong". Ils devraient constater que les écritures sont désormais partielles
 * et qu'ils doivent donc utiliser un tel mécanisme.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/select.h>
#include <unistd.h>

static char pong[4] = "pong";
static char ping[4] = "ping";

void
enfant(int ecrfd, int lecfd) {
    int off_pong = 0;
    char lus[sizeof ping];
    int off_ping = 0;
    fd_set ecr;
    fd_set lec;
    int nfd = (ecrfd < lecfd? lecfd : ecrfd) + 1;
    long pings_a_repondre = 0;
    int fin_de_fichier = 0;

    while (!fin_de_fichier || pings_a_repondre > 0) {
	int ret;

	FD_ZERO(&ecr);
	if (pings_a_repondre > 0)
	    FD_SET(ecrfd, &ecr);
	FD_ZERO(&lec);
	if (!fin_de_fichier)
	    FD_SET(lecfd, &lec);

	ret = select(nfd, &lec, &ecr, NULL, NULL);
	if (ret == -1) {
	    perror("select");
	    exit(EXIT_FAILURE);
	}
	if (FD_ISSET(ecrfd, &ecr)) {
	    ret = write(ecrfd, pong + off_pong, sizeof pong - off_pong);
	    if (ret == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	    }
	    off_pong += ret;
	    if (off_pong == sizeof pong) {
		off_pong = 0;
		pings_a_repondre--;
	    }
	}

	if (FD_ISSET(lecfd, &lec)) {
	    ret = read(lecfd, lus + off_ping, sizeof ping - off_ping);
	    if (ret == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	    } else if (ret == 0) {
		fin_de_fichier = 1;
		close(lecfd);
		continue;
	    }

	    off_ping += ret;
	    if (off_ping == sizeof ping) {
		if (strncmp(lus, ping, sizeof ping)) {
		    fprintf(stderr, "enfant : donnees erronnees\n");
		    exit(EXIT_FAILURE);
		}
		off_ping = 0;
		pings_a_repondre++;
	    }
	}
    }
    close(ecrfd);
}

void
parent(int ecrfd, int lecfd, long nb) {
    int off_ping = 0;
    char lus[sizeof pong];
    int off_pong = 0;
    fd_set ecr;
    fd_set lec;
    int nfd = (ecrfd < lecfd? lecfd : ecrfd) + 1;
    long pongs_recus = 0;
    int fin_de_fichier = 0;

    while (nb > 0 || !fin_de_fichier) {
	int ret;

	FD_ZERO(&ecr);
	if (nb > 0)
	    FD_SET(ecrfd, &ecr);
	FD_ZERO(&lec);
	if (!fin_de_fichier)
	    FD_SET(lecfd, &lec);

	ret = select(nfd, &lec, &ecr, NULL, NULL);
	if (ret == -1) {
	    perror("select");
	    exit(EXIT_FAILURE);
	}
	if (FD_ISSET(ecrfd, &ecr)) {
	    ret = write(ecrfd, ping + off_ping, sizeof ping - off_ping);
	    if (ret == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	    }
	    off_ping += ret;
	    if (off_ping == sizeof ping) {
		off_ping = 0;
		nb--;
		if (nb == 0)
		    close(ecrfd);
	    }
	}

	if (FD_ISSET(lecfd, &lec)) {
	    ret = read(lecfd, lus + off_pong, sizeof pong - off_pong);
	    if (ret == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	    } else if (ret == 0) {
		fin_de_fichier = 1;
		close(lecfd);
		continue;
	    }

	    off_pong += ret;
	    if (off_pong == sizeof pong) {
		if (strncmp(lus, pong, sizeof pong)) {
		    fprintf(stderr, "parent : donnees erronnees\n");
		    exit(EXIT_FAILURE);
		}
		off_pong = 0;
		pongs_recus++;
	    }
	}
    }
    printf("pongs reçus : %ld\n", pongs_recus);
}

int
main(int argc, char *argv[]) {
    char *end_of_arg;
    int parent_enfant[2];
    int enfant_parent[2];
    pid_t pid;
    long nb;

    if (argc != 2)
	goto usage;

    nb = strtol(argv[1], &end_of_arg, 10);
    if (*end_of_arg != '\0')
	goto usage;

    if (pipe(parent_enfant) == -1) {
	perror("pipe 1");
	return EXIT_FAILURE;
    }

    if (pipe(enfant_parent) == -1) {
	perror("pipe 2");
	return EXIT_FAILURE;
    }

    pid = fork();
    switch (pid) {
    case -1:
	perror("fork");
	return EXIT_FAILURE;
    case 0:
	/* enfant */
	close(enfant_parent[0]);
	close(parent_enfant[1]);
	enfant(enfant_parent[1], parent_enfant[0]);
	break;
    default:
	/* parent */
	close(enfant_parent[1]);
	close(parent_enfant[0]);
	parent(parent_enfant[1], enfant_parent[0], nb);
	break;
    }

    return EXIT_SUCCESS;

usage:
    fprintf(stderr, "usage: %s nbpings\n", argv[0]);
    return EXIT_FAILURE;
}
