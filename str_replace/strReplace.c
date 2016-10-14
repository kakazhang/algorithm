#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strReplace(char *str, char* sub, char* needle) {
    if (!str || !sub || !needle) {
        printf("input string is NULL\n");
        return;
    }
    
    int srclen = strlen(str) * 2;
    int sublen = strlen(sub);
    int nlen = strlen(needle);

    char *start = str;
    char *end = NULL;

    char *newStr = (char *)malloc(srclen);
    if (!newStr) {
        perror("malloc");
        return;
    }

    int count = srclen;
    char *ptr = newStr;
    while (start &&  (end = strstr(start, sub)) ) {
        int len = end - start;
        if (count < len) {
            newStr = (char *)realloc(newStr, 2 * srclen);
            srclen *= 2;
        }

        //copy source
        strncpy(ptr, start, len);
        ptr += len;
        //copy replace string
        strncpy(ptr, needle, nlen);
        ptr += nlen;

        start = end + sublen;
        count -= (len+sublen);
    }

    if (newStr != ptr) {
        strcat(newStr, start);
        printf("%s\n", newStr);
    }

    if (newStr)
        free(newStr);
}

int main() {
    char msg[] = {"hello,this is kaka from xuzhou,Jiangsu province"};

    strReplace(msg, "kaka", "zhanglin");

    return 0;
}
