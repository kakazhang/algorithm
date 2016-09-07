/*************************************************************************
	> File Name: quick_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月07日 星期三 21时58分17秒
 ************************************************************************/

#include<stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int left, int right, int pivot) {
    int store_index = 0;
    int i;
    int val = arr[pivot];
    
    swap(&arr[pivot], &arr[right]);

    for (i = 0; i < right; i++) {
        if (arr[i] < val) {
            swap(&arr[store_index++], &arr[i]);
        }
    }

    swap(&arr[store_index], &arr[right]);

    return store_index;
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int m = partition(arr, left, right, (left+right)/2);

        quick_sort(arr, left, m-1);
        quick_sort(arr, m+1, right);
    }
}
