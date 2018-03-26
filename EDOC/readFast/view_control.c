#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<stdlib.h>
#include<ncurses.h>

#define TER_FLAG (isatty(STDOUT_FILENO) & isatty(STDIN_FILENO))
#define MAX_BUFF 40

char *poem[] = {"hellow everyone","I love You","abcdefgh","13579","sucksucksuck","fuckfuckfuckfuckfuck"};

char buff[100] = "abcd skas as";

char *get_tty_name(void){

   return( getenv("PGP_TTY") );

}
void clrt_end(int pos_x, int pos_y){
    /* del x to $ */
    move(pos_x,pos_y);
    clrtoeol();
}

int display_rollback(char **text, int length, int start_x, int start_y) {
    int i_num = 0;
    int j_num = 0;
    for(;i_num<=length-1; i_num++) {
        move(start_x + i_num, start_y) ;
        printw("%s",*(text+i_num));
        refresh();
    }
    i_num = 0;
    while(1) {
        i_num = ((i_num+1) % length);
        erase();
        for(; j_num<=length-1; j_num++ ){
            /* move(start_x + (i_num + j_num) % length, start_y); */
            clrt_end(start_x + i_num + j_num, start_y);
            printw("%s",*(text + j_num));
        }
        refresh();
        j_num = 0;


    }
}



int main(void){

    /* struct termios tty_str; */
    /* if( tcgetattr(STDIN_FILENO, &tty_str) < 0 ) { */
        /* return 111; */
    /* } */


    /* char* tty_name = getenv("GPG_TTY"); */

    /* int ter_flag = TER_FLAG; */
    /* int fd_tty; */
    /* int f; */
    /* if ( (NULL != (fd_tty = fopen(tty_name, "r+"))) && ter_flag) { */
        /* setbuf(fd_tty, buff); */
        /* fprintf("ssss5", fd_tty); */
    /* } */

    initscr();
        display_rollback(poem, 4, 10, 10);
    endwin();

    return 0;


}
