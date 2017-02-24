/*************************************************************************
	> File Name: duplicate.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月24日 星期五 18时05分05秒
 ************************************************************************/

#include <stdio.h>

#define MAX 20

int hasDup(int arr[], int len) {
    int a[MAX];
    int i;

    for (i = 0; i < MAX; i++)
        a[i] = 0;

    for (i = 0; i < len; i++) {
        int element = arr[i];
        a[element]++;
        if (a[element] > 1)
           return 1;
    }

    return 0;
}

int main() {
    int arr[] = {2, 8, 19, 3, 4};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("has duplicate?%d\n", hasDup(arr, len));
    return 0;
}
