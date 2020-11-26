#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len){
    if(!little) return 0;
    const char *_big = big;
    const char *_little = little;
    char *ptr = mx_memchr(_big, _little[0], big_len);
    while(ptr != 0){
        if(mx_memcmp(ptr, _little, little_len) == 0) return (char *)ptr;
        else ptr = mx_memchr(ptr + 1, _little[0], big_len);
    }
    return 0;
}
