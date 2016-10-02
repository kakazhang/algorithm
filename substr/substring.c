/*************************************************************************
	> File Name: substring.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月02日 星期日 13时24分18秒
 ************************************************************************/

#include <stdio.h>

char* substring(char *str, const char* sub) {
    char *begin;

    char *p1 =str;
    const char *p2= sub;

    while (*p1) {
        char *pbegin = p1;
        while (*p1 && *p2 && *p1==*p2) {
            p1++;
            p2++;

        }

        if (*p2 == '\0')    
            return pbegin;
        
        p1 = pbegin + 1;
        p2 = sub;
    }

    return NULL;
}

int main() {
    char str[] = {"hello, kaka"};
    char *sub = "kaka0";

    char *p = substring(str, sub);
    if (p != NULL)
        printf("%s\n", p);

    return 0;
}
