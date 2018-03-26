#include<stdio.h>
#include<wchar.h>

FILE *test_file_flow = NULL;
int main(void){

    int flow_flag = 0;
    test_file_flow = fopen("./test_file","ab+");
    flow_flag = fwide(test_file_flow, 4);
    printf("%d",flow_flag);
    return 0;

}
