#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
    int fds[2];
    int in_next = STDIN_FILENO;
    pid_t pid_enfant;
    pid_t pid;
    int status;

    if (argc <= 1) {
	fprintf(stderr, "usage: %s command --- ... --- command\n", argv[0]);
	return EXIT_FAILURE;
    }

    for (;;) {
	char **args = ++argv;

	while (argv[0] != NULL && strcmp(argv[0], "---"))
	    argv++;

	if (argv[0] != NULL) {
	    /* On n'est pas le dernier processus du pipeline */
	    if (pipe(fds) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	    }
	}

	pid_enfant = fork();
	switch (pid_enfant) {
	case -1:
	    perror("fork");
	    exit(EXIT_FAILURE);
	case 0:
	    /* enfant */
	    if (in_next != STDIN_FILENO) {
		/* On n'est pas le premier processus du pipeline */
		close(STDIN_FILENO);
		dup(in_next);
		close(in_next);
	    }

	    if (argv[0] != NULL) {
		/* On n'est pas le dernier processus du pipeline */
		close(fds[0]);
		close(STDOUT_FILENO);
		dup(fds[1]);
		close(fds[1]);
	    }

	    argv[0] = NULL;
	    execvp(args[0], args);
	    perror("execvp");
	    exit(EXIT_FAILURE);
	}
	/* parent */
	if (in_next != STDIN_FILENO)
	    close(in_next);

	if (argv[0] == NULL)
	    break;

	close(fds[1]);
	in_next = fds[0];
    }

    /* On attend le bon enfant */
    do {
	pid = wait(&status);
	if (pid == -1) {
	    perror("wait");
	    exit(EXIT_FAILURE);
	}
    } while (pid != pid_enfant);

    if (WIFEXITED(status))
	return WEXITSTATUS(status);
    else {
	if (WIFSIGNALED(status))
	    fprintf(stderr, "Signal %d\n", WTERMSIG(status));

	return EXIT_FAILURE;
    }
}
