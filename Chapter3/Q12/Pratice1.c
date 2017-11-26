#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
 
 
int dirYesNo(char fname[]);//디렉터리 인지 아닌지 검사
void printUseage(); //  사용법 출력
int fileCopy(char *filename, char *newfilename);// 단순 파일 복사
int dirCopy(char* dirpath, char* newdirpath);//디렉터리 복사 리커시브
 
int main(int argc, char* argv[])
{
    if(argc==3)
    {//파일 복사
        //rintf("%s ", argv[1]);   
        if(dirYesNo(argv[1])==1)
        {// 디렉터리 일경우 에러
            //rintf("디렉터리임...",dirYesNo(argv[1]));   
            printf("디렉터리 입니다. \n");
            printUseage();
            exit(1);
            return 0;
        }
        else
        {
            // 파일일경우 정상적으로 파일 복사.
 
            if(fileCopy(argv[1], argv[2]))
                printf(" '%s'을(를) '%s'으로 성공적으로 파일 복사완료!!! \n",argv[1],argv[2] );
            else{
                printf("파일복사 실패!!!!!\n");
                exit(1);
            }
        }
        //rintf("ok ",dirYesNo(argv[1]));
    }
    else if(argc==4)
    {//디렉터리 복사
        //    printf("argv[1] : %s ",argv[1]);
        if(!strcmp(argv[1],"-d"))
        {
            printf("디렉터리 복사를 시작합니다. \n");
            if(!dirCopy(argv[2],argv[3]))
            {
                printf("디렉터리 복사 완료 !!. \n");
            }
            else{
                printf("디렉터리 복사 실패 \n");
                exit(1);
            }
        }
        else
        {
            printf("옵션을 잘못입력하였습니다.!! \n");
            printUseage();
            exit(1);
        }
 
 
    }
    else
    {
        printUseage();
        return 0;
    }
    return 0;
}
 
int fileCopy(char* filename, char *newfilename)
{
 
    FILE * f;// 읽을파일
    FILE * g;// 새로 쓸파일
    int cnt=0;
    char buff[1];
    printf(" ");
    if((f=fopen(filename, "rb"))==NULL)
    {
        printf("파일을 열수없습니다 \n");
        exit(1);
    }
 
    if((g=fopen(newfilename, "wb"))==NULL)
    {
        //    printf("%s ",newfilename);
        printf("대상파일을 열수없습니다 \n");
        exit(1);
    }
 
    while(!feof(f))
    {
        fread(&buff,1,1,f);
        if(!feof(f))// 이걸 안하면 한바이트가 더 복사가됨...
            fwrite(&buff, 1,1, g); cnt++;
 
    }
 
    fclose(f);
    fclose(g);
 
    printf(" '%s'을(를) '%s'으로 복사완료!!!(%.2lfKB) \n",filename,newfilename,(double)cnt/1024 );
    return 1;
 
}
 
int dirYesNo(char fname[])
{
    struct stat buf; //파일 상태 구조체
    lstat(fname,&buf);
    //  printf("%s ---- %d/n",fname,(int)(mode_t) buf.st_mode);
    return S_ISDIR(buf.st_mode); //디렉터리 인지 아닌지?
}
 
void printUseage()
{
    printf("error!! 잘못 입력 했습니다. \n");
    printf("Useage \n");
    printf("디렉터리 복사 : mycopy [-d] 원본 사본 \n");
    printf("파일복사 : mycopy 원본 사본 \n");
}
 
mode_t st_modeTomode_t(char *filepath)
{
    struct stat buf;
    lstat(filepath,&buf);
    return (mode_t)buf.st_mode;//st_mode 를 mode_t로 변환
}
 
int dirCopy(char* dirpath, char* newdirpath)
{
 
    //mkdir(newdirpath,st_modeTomode_t(dirpath)); // 폴더 생성
    DIR *dir_info        = NULL;
    struct dirent    *dir_entry        = NULL;
        char filepath[1000];
    char newfilepath[1000];
    dir_info = opendir(dirpath);
 
    if ( NULL == dir_info)
    {
        printf("%s 디렉토리를 오픈 할 수 없습니다.! \n",dirpath);
            exit(1);
    }
    else
    {
        while( (dir_entry = readdir( dir_info) ) != NULL )
        {
            mkdir(newdirpath,st_modeTomode_t(dirpath)); // 폴더 생성
            if( (strcmp(dir_entry->d_name, "..") == 0 ) ||
                    (strcmp(dir_entry->d_name, ".") == 0 ))          // 상위폴더는 제외
                continue;
 
            sprintf(filepath, "%s/%s", dirpath, dir_entry->d_name);
                sprintf(newfilepath,"%s/%s",newdirpath,dir_entry->d_name);
 
                //rintf("--------%s ", dir_entry->st_mode);
               
               
                if(dirYesNo(filepath)) //디렉터리 인가?
                {
                    mkdir(newdirpath,st_modeTomode_t(filepath)); //폴더생성
                    dirCopy(filepath,newfilepath);//리커시브 호출
                }
                else
 
                    fileCopy(filepath,newfilepath);
            // 파일 복사
 
        }
    }
 
    closedir(dir_info);
 
    return 0;
 
 
}
