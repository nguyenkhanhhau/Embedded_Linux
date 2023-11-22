#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>


int main() {
    int fd, wr_t;      //fd file descriptor
    char buf[32] ="Hello Mr.Phong and everyone\n";
    struct stat infor;
    
    fd =open("test.txt", O_RDWR | O_CREAT , 0777);
    if(fd==-1)
    {
        printf("open file failed \n");
        return -1;
    }
    wr_t =write(fd, buf, strlen(buf));
    if(wr_t==-1)
    {
        printf("write file failed \n");
        return -1;
    }
    printf("Filename: test.txt\n");
    printf("File type:\n");
    printf("File Last Modification: %s\n",ctime(&infor.st_mtime));
    printf("File size: %d\n", infor.st_size);

    switch (infor.st_mode & S_IFMT)
    {
        case S_IFBLK:  
            printf("block device\n");
             break;
        case S_IFCHR:  
            printf("character device\n");        
            break;
        case S_IFDIR:  
            printf("directory\n");
            break;
         case S_IFIFO:  
            printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("symlink\n");    
            break;
        case S_IFREG:  
            printf("regular file\n");    
            break;
        case S_IFSOCK: 
            printf("socket\n");     
            break;

        close(fd);
        return 0;
    }   
    

















}
