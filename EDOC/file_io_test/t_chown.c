#include<stdio.h>
#include<sys/stat.h>
struct stat *buf;


int main(void) {
    int test;
    test = stat("/home/junn/EDOC/file_io_test/test_file", buf);

    printf("%L",(buf->st_atime));
    /* chown("../test_file", buf->st_uid, buf->st_gid); */
    return 0;
}
