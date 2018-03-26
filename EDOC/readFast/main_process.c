#include<stdio.h>
#define __INFORMATION ( \
       " \
        Welcome! a fast & simple read-demo, you should add a parameter like a filename to \
import in this tool,such as ./program -f filename                                         \
        "                                                                                 \
        )                                                                                 \


int main(int argc, char **argv) {
    if (1 == argc) {
        printf(__INFORMATION)   ;
        return;
    }
    else if(3 == argc && 0 == strcmp(argv[1],"-f") ) {
        /*handle import*/
    }

  }
