#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    //int fd = open("./log",O_CREAT | O_RDWR);
    int fd = open("./log",O_CREAT | O_RDWR,S_IRWXU);
    if(fd < 0){
        perror("open");
        return -1;
    }
    close(1);
    int new_fd = dup2(fd,1);
    if(new_fd < 0){
        perror("dup2");
        exit(2);
    }
    close(fd);
    char buf[1024];
    while(1){
        memset(buf,'\0',sizeof(buf));
        read(0,buf,sizeof(buf)-1);
        if(strncmp("quit",buf,4) == 0){
            break;
        }
        printf("%s",buf);
        fflush(stdout);
    }
    close(new_fd);
    return 0;
}
