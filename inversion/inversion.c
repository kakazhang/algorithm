#include <stdio.h>
#include <stdlib.h>

int Merge(int arr[], int tmpArr[], int lstart, int rstart, int rend) {
    int low = lstart;
    int high = rend;

    int lend = rstart - 1;
    int inv = 0;

    int tmp = lstart;
    while (lstart <= lend && rstart <= rend) {
        if (arr[lstart] < arr[rstart]) {
            tmpArr[tmp++] = arr[lstart++];
        } else {
            tmpArr[tmp++] = arr[rstart++];
            inv += (lend - lstart);
        }
    }

    while (lstart <= lend) 
        tmpArr[tmp++] = arr[lstart++];

    while (rstart <= rend) 
        tmpArr[tmp++] = arr[rstart++];

    int i;
    for (i = low; i <= high; i++)
        arr[i] = tmpArr[i];

    return inv;
}

int MSort(int arr[], int tmpArr[], int start, int end) {
    int inv = 0;
    int mid;

    if (start < end) {
        mid = (start + end) / 2;
        inv = MSort(arr, tmpArr, start, mid);
        inv += MSort(arr, tmpArr, mid+1, end);

        inv += Merge(arr, tmpArr, start, mid+1, end);
    }

    return inv;
}

int MergeSort(int arr[], int len) {
    int *tmpArr = (int *)malloc(sizeof(int) * len);
    if (tmpArr == NULL) {
        printf("no space\n");
        return -1;
    }

    int inversions = MSort(arr, tmpArr, 0, len-1);
    //printf("inversions:%d\n", inversions);
    
    free(tmpArr);

    return inversions;
}

void show(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) 
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    show(arr, len);
    int inv = MergeSort(arr, len);
    show(arr, len);
    printf("inversions:%d\n", inv);

    return 0;
}
