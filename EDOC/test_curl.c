#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<curl/multi.h>


#define THREAD_NUM 20
const char *url_list = "http://www.baidu.com";
static size_t cb(char *d,size_t n,size_t l,void *p){
    (void) p, (void) d;
    return (n*l);
}

void init_add_handle(CURLM *clm, int i){

    CURL *eh = curl_easy_init();
    curl_easy_setopt(eh, CURLOPT_W, cb)
    curl_easy_setopt(eh, CURLOPT_HEADER, 0L);
    curl_easy_setopt(eh, CURLOPT_URL, urls[i]);
    curl_easy_setopt(eh, CURLOPT_PRIVATE, urls[i]);
    curl_easy_setopt(eh, CURLOPT_VERBOSE, 0L);

}

int main(void) {

    //curl_multi_setopt;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url_list);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

}
