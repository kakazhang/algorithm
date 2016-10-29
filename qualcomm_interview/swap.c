/*************************************************************************
	> File Name: swap.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月14日 星期五 17时01分57秒
 ************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap_add(int *pa, int *pb) {
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

void swap_xor(int *pa, int *pb) {
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
}

void swap_str(char str1[], char str2[]) {
    int len = strlen(str1);

    char *tmp = (char *)malloc(len+1);

    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);

    return;
}
