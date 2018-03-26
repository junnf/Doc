#include<stdio.h>
#include<unistd.h>

int main(void) {
    char *init_env[] = {"USER=root"};
    pid_t p;
    int a = 1;
    if ((p = fork()) < 0) {
        exit(1) ;
    }
    else if(0 == p) {
        /* execle("/usr/bin/ls","." , (char *)0, init_env); */
        a=a*2;
        /* waitpid(p, NULL, 0); */
        printf("aaaaa");
    }
    else {
        a = a+1;
        printf("%d",a);
    }

}
