#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[], int start, int end) {
    while(start < end) {
        int tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
}

/*
*@str: array of string to rotate
*@len: array length
*@rot: rotate index(not array index)
* */
void rotate(char str[], int len, int rot) {
    reverse(str, 0, rot-1);
    reverse(str, rot, len-1);
    reverse(str, 0, len-1);
}

int main() {
    char str[] = {"hello"};
    int len = strlen(str);

    printf("str:%s\n",str);
    rotate(str, len, 2);
    printf("str:%s\n",str);

    return 0;
}
