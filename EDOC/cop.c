#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<curl/multi.h>
#include<sys/select.h>
#include<unistd.h>


#define THREAD_NUM 20
const char *url_list[5] = {
    "http://www.baidu.com",  \
    "http://www.renren.com", \
    "http://www.amazon.cn",  \
    "http://www.renren.com", \
    "http://www.amazon.cn"};

static size_t cb(char *d,size_t n, size_t l,void *p){
    (void)d;
    (void)p;
    return n*l;
}

static void init(CURLM *curl, int i){
    CURL *eh = curl_easy_init();

    curl_easy_setopt(eh, CURLOPT_WRITEFUNCTION, cb);
    curl_easy_setopt(eh, CURLOPT_HEADER, 0L);
    curl_easy_setopt(eh, CURLOPT_URL,url_list[i]);
    curl_easy_setopt(eh, CURLOPT_PRIVATE, url_list[i]);
    curl_easy_setopt(eh, CURLOPT_VERBOSE, 0L);
    curl_multi_add_handle(curl, eh);
}

int main(void) {

    /* CURL *curl = curl_easy_init(); */
    /* if(curl) { */
        /* CURLcode res; */
        /* curl_easy_setopt(curl, CURLOPT_URL, url_list[0]); */
        /* res = curl_easy_perform(curl); */
        /* curl_easy_setopt(curl, CURLOPT_URL, url_list[1]); */
        /* res = curl_easy_perform(curl); */
        /* curl_easy_setopt(curl, CURLOPT_URL, url_list[2]); */
        /* res = curl_easy_perform(curl); */
        /* curl_easy_setopt(curl, CURLOPT_URL, url_list[3]); */
        /* res = curl_easy_perform(curl); */
        /* curl_easy_setopt(curl, CURLOPT_URL, url_list[4]); */
        /* res = curl_easy_perform(curl); */
        /* //curl_easy_cleanup(curl); */

    /* } */
    /* int set_test; */
    /* fd_set readset,writeset; */
    /* FD_ZERO(&readset); */
    /* FD_ZERO(&writeset); */
    /* FD_SET(0, &readset); */
    /* FD_SET(3, &readset); */
    /* FD_SET(1, &writeset); */
    /* FD_SET(2, &writeset); */
    /* set_test = select(4, &readset, &writeset, NULL, 5); */
    /* printf("%d",set_test); */
    int init_counter = 0;
    int U = -1;
    int Q;
    int M;
    long L;
    CURLM * curlm;
    CURLMsg *curlmsg;
    fd_set R,W,ERR;
    struct timeval T;
    curl_global_init(CURL_GLOBAL_ALL);

    curlm = curl_multi_init();
    for (; init_counter<5; init_counter++){
        init(curlm, init_counter);
    }
    while(U){
      curl_multi_perform(curlm, &U);
      if (U) {
        FD_ZERO(&R);
        FD_ZERO(&W);
        FD_ZERO(&ERR);
        if(curl_multi_fdset(curlm, &R, &W, &ERR, &M)) {
            fprintf(stderr, "E: curl_multi_fdset\n");
            return EXIT_FAILURE;
        }
        if(curl_multi_timeout(curlm, &L)) {
            fprintf(stderr, "E: curl_multi_timeout\n");
            return EXIT_FAILURE;
        }
        if(L == -1)
            L = 100;
        if(-1 == M)
            sleep((unsigned int)L / 1000);
        else {
            T.tv_sec = L / 1000;
            T.tv_usec = 0;
            if (select(M+1,&R,&W,&ERR,&T) == -1) {
                fprintf(stderr, "E: select(%i,,,,%li): %i: %s\n",
                                      M+1, L, errno, strerror(errno));
            }
        }
      }

    }
    while((curlmsg = curl_multi_info_read(curlm, &Q))){
        if(curlmsg->msg == CURLMSG_DONE) {
        char *url;
        CURL *e = curlmsg->easy_handle;
        curl_easy_getinfo(curlmsg->easy_handle, CURLINFO_PRIVATE, &url);
        fprintf(stderr, "R: %d - %s <%s>\n",
                                 curlmsg->data.result, curl_easy_strerror(curlmsg->data.result), url);
        printf("%s",url);
        }

    }
    sleep(55000);

}
