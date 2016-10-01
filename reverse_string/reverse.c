/*************************************************************************
	> File Name: reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月30日 星期五 22时57分02秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void reverse(char str[], int len) {
    int left = 0;
    int right = len;
    int tmp;

    while (left < right) {
        tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;

        left++;
        right--;
    }
}

int main() {
    char str[] = {"hello"};
    int len = strlen(str);

    reverse(str, len);

    //printf("%s\n", str);
    int i;
    for (i = 0; i <= len; i++)
        printf("%c", str[i]);

    printf("\n");
    return 0;
}
