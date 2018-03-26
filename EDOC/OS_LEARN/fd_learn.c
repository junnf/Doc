#include<fcntl.h>
#include<unistd.h>
char buff[2096]="ssssssssssssddd\0";

int main(void) {
    int fd_1;

    fd_1 = open("./cop", O_WRONLY | O_RDONLY | O_SYNC );
    write(fd_1, buff, 128);

    return 0;

}
