#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <limits.h>
#include <pwd.h>
#include <grp.h>

#define CHK(X)     \
                do if ((X)<0) { perror(#X); exit(1); } while (0)
#define CHK_PTR(X) \
                do if (!(X)) { perror(#X); exit(1); } while (0)

#define OPT_ALL        0x01
#define OPT_LONG       0x02
#define OPT_RECURSIVE  0x04


char mode_to_char(mode_t m){
        if (S_ISREG(m)) return '-';
        if (S_ISDIR(m)) return 'd';
        if (S_ISLNK(m)) return 'l';
        if (S_ISCHR(m)) return 'c';
        if (S_ISBLK(m)) return 'b';
        if (S_ISFIFO(m)) return 'f';
        if (S_ISSOCK(m)) return 's';
        return '?';
}

void getusername(char *buffer, uid_t uid) {
        struct passwd *uinfo;
        if ((uinfo = getpwuid(uid)))
                strcpy(buffer, uinfo->pw_name);
        else
                snprintf(buffer, _POSIX_LOGIN_NAME_MAX, "%u", uid);
}

void getgrpname(char *buffer, gid_t gid) {
        struct group *ginfo;
        if ((ginfo = getgrgid(gid)))
                strcpy(buffer, ginfo->gr_name);
        else
                snprintf(buffer, _POSIX_LOGIN_NAME_MAX, "%u", gid);
}

void ls(char *path, int opts) {
        DIR *dir; // for open/close dir
        struct dirent *entry; // for readdir
        struct stat stat; // for stat 
        char buffer[PATH_MAX]; // for filename
        char *fname; // for current filename
        char login[_POSIX_LOGIN_NAME_MAX];
        char group[_POSIX_LOGIN_NAME_MAX];

        fname = stpcpy(buffer, path);
        *fname++ = '/';

        CHK_PTR(dir = opendir(path));
        printf("%s:\n", path);

        while ((entry = readdir(dir))) {
	  if (!(opts & OPT_ALL) && entry->d_name[0] == '.') continue;
	  
	  strcpy(fname, entry->d_name); // concatenate filename
	  if (opts & OPT_LONG) {
	    CHK(lstat(buffer, &stat));
	    getusername(login, stat.st_uid);
	    getgrpname(group, stat.st_gid);
	    
	    printf("%c%3o %3d\t%s:%s\t%zd\t%s\t%s",
		   mode_to_char(stat.st_mode), stat.st_mode & 0777, stat.st_nlink,
		   login, group, stat.st_size, fname, ctime(&stat.st_mtime));
	  } else
	    printf("%s\n", fname);
        }
	
        if (opts & OPT_RECURSIVE) {
	  rewinddir(dir); // Let's start again
	  while ((entry = readdir(dir))) {
	    if (!(opts & OPT_ALL) && entry->d_name[0] == '.') continue;
	    if (!(strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))) continue; // We have to always skip . and ..

	    strcpy(fname, entry->d_name); // concatenate filename
	    CHK(lstat(buffer, &stat));
	    if (S_ISDIR(stat.st_mode)) {
	      printf("\n");
	      ls(buffer, opts);
	    }
	  }
        }
	
        CHK(closedir(dir));
}


int main (int argc, char **argv) {
        int opts = 0;
        int ch;
        while ((ch = getopt(argc, argv, "lar")) != -1)
	  switch (ch) {
	  case 'l':
	    opts |= OPT_LONG;
	    break;
	  case 'a':
	    opts |= OPT_ALL;
	    break;
	  case 'r':
	    opts |= OPT_RECURSIVE;
                }
	
        argc -= optind;
        argv += optind;

        ls(argc , *argv : ".", opts);
}
