#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str){
    if (!str || mx_strlen(str) <= 0) return NULL;
    int space = 0;
    char *temp = mx_strtrim(str);
    if(!temp) return NULL;
    for (int i = 0; i < mx_strlen(temp); i++)
        if(mx_isspace(temp[i]) && mx_isspace(temp[i + 1])) space++;
    int new_size = mx_strlen(temp) - space;
    char *res = mx_strnew(new_size);
    if(!res) return NULL;
    int first_space = 0;
    for (int i = 0, j = 0; i < new_size; j++) {
        if (mx_isspace(temp[j])){
            if(first_space == 1) continue;
            temp[j] = ' ';
            first_space = 1;
        }
        else first_space = 0;
        res[i] = temp[j];
        ++i;
    }
    mx_strdel(&temp);
    return res;
}
