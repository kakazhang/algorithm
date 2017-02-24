/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月07日 星期三 22时06分59秒
 ************************************************************************/

#include<stdio.h>

extern void quick_sort(int arr[], int left, int right);

void test_sort() {
    int arr[] = { 12, 3, 21, 126, 2, 128, 2048};
    int len = sizeof(arr)/sizeof(arr[0]);

    int i;
    printf("before sort\n");
    for (i = 0; i < len; i++)
        printf("%d\n", arr[i]);
    
    quick_sort(arr, 0, len-1);
    printf("after sort:\n");
    for (i = 0; i < len; i++)
        printf("%d\n", arr[i]);
}

int main() {
    test_sort();
    return 0;
}
