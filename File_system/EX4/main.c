#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>
int main() {

int fd , wr_t ;
char buf[32] =" test flag O_APPEND\n";
fd =open("text.txt", O_RDWR | O_APPEND, 0777);
if(fd==-1)
{
    printf("open file failed\n");
    return -1;
}
wr_t =write(fd, buf, strlen(buf));
if(wr_t==-1)
{
    printf("write file failed \n");
    return -1;
}

//lseek(fd, buf, SEEK_SET);
return 0;
}


//lệnh lseek SEEL_SET đưa con trỏ phần đầu file nhưng nếu không có flag O_APPEND thì con trỏ vẫn ở cuối file dù chúng ta đã set SEEK_SET
