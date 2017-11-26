#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX 300

void ListFirst();
void Able();
void Etc();

DIR *dp;
struct dirent *dirp;
const char *dir;
char filename[MAX];
char list[MAX];
char buf[MAX];
struct stat info;
int ind = 0;

int main(int argc, char *argv[]){
    int count = 0;

    if(argc == 1)
        dir=".";
    else
        dir = argv[1];

    dp = opendir(dir);
    if(dp == NULL)
        puts("Open Error!!");

    while(dirp = readdir(dp)){
            count++;
    }
    printf("total : %d\n", count);

    rewinddir(dp);

    while(dirp = readdir(dp)){
        ListFirst();
        Able();
        Etc();
    }

    closedir(dp);
    return 0;
}

void ListFirst(){
    ind = 0;

    if(strncmp(dirp->d_name, ".", 1) == 0)
        return;
    sprintf(filename, "%s/%s", dir, dirp->d_name);
    lstat(filename, &info);

    switch(info.st_mode & S_IFMT){
        case S_IFREG:
            list[ind++] = '-';
            break;
	case S_IFDIR:
	    list[ind++] = 'd';
	    break;
	case S_IFIFO:
	    list[ind++] = 'p';
	    break;
	case S_IFLNK:
	    list[ind++] = 'l';
	    break;
    }
}

void Able(){
    int i;
    
    for(i = 0; i < 3; i ++){
        if(info.st_mode & (S_IREAD >> i * 3))
            list[ind++] = 'r';
        else
            list[ind++] = '-';
        if(info.st_mode & (S_IWRITE >> i * 3))
            list[ind++] = 'w';
        else
            list[ind++] = '-';
        if(info.st_mode & (S_IEXEC >> i * 3))
            list[ind++] = 'x';
        else
            list[ind++] = '-';

    }
}

void Etc(){
    struct passwd *uid;
    struct group *gid;

    printf("%s%5d", list, info.st_nlink);

    uid = getpwuid(info.st_uid);
    printf(" %s", uid->pw_name);
    gid = getgrgid(info.st_gid);
    printf(" %s", gid->gr_name);

    sprintf(buf, " %d %s", info.st_size, ctime(&info.st_mtime));
    buf[strlen(buf) -1] = '\0';
    printf("%s %s\n", buf, dirp->d_name);
}























