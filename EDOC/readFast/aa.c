#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<stdlib.h>

#define TER_FLAG (isatty(STDOUT_FILENO) & isatty(STDIN_FILENO))
#define MAX_BUFF 40
char buff[100] = "abcd skas as";

char *get_tty_name(void){

   return( getenv("PGP_TTY") );

}

int main(void){

    struct termios tty_str;
    if( tcgetattr(STDIN_FILENO, &tty_str) < 0 ) {
        return 111;
    }


    char* tty_name = getenv("PGP_TTY");
    int ter_flag = TER_FLAG;
    int fd_tty;
    if ( (NULL != (fd_tty = fopen(tty_name, "r+"))) && ter_flag) {
        w

    }


}
