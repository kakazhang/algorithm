#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int len) {
    int i, j;

    for (i = 1; i < len; i++) {
        int tmp = arr[i];

        for (j = i; j > 0 && arr[j-1] > tmp; j--)
            arr[j] = arr[j-1];

        arr[j] = tmp;
    }
}

void shellSort(int arr[], int len) {
    int i, j;
    int increment;
    
    for (increment = len/2; increment > 0; increment--) {
        for (i = increment; i < len; i++) {
            int tmp = arr[i];
            for (j = i; j >= increment && arr[j-increment] > tmp; j -= increment) {
                arr[j] = arr[j-increment];
            }
            arr[j] = tmp;
        }
    }
}

//Bubble sort
void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bubble(int arr[], int N) {
    int i, j;

    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            if (arr[j] < arr[i])
                swap(&arr[i], &arr[j]);
        }
    }
}

void Merge(int arr[], int tmpArr[], int lStart, int rStart, int rEnd) {
    int len = rEnd - lStart + 1;
    int lEnd = rStart - 1;
    int tmpPos = lStart;
    int low = lStart, high = rEnd;

    while (lStart <= lEnd && rStart <= rEnd) {
        if (arr[lStart] < arr[rStart])
            tmpArr[tmpPos++] = arr[lStart++];
        else
            tmpArr[tmpPos++] = arr[rStart++];
    }

    while (lStart <= lEnd) {
        tmpArr[tmpPos++] = arr[lStart++];
    }

    while (rStart <= rEnd) {
        tmpArr[tmpPos++] = arr[rStart++];
    }

    int i;
    for (i = low; i <= high; i++) {
        arr[i] = tmpArr[i];
    }
}

//merge sort
void MSort(int arr[], int tmpArr[], int l, int r) {
    int center;
    if (l < r) {
        center = (l + r) / 2;
        MSort(arr,tmpArr, l, center);
        MSort(arr, tmpArr, center+1, r);
        Merge(arr, tmpArr, l, center+1, r);
    }
}

void MergeSort(int arr[], int len) {
    int *tmpArr = (int *)malloc(sizeof(int) * len);
    if (tmpArr == NULL) {
        perror("malloc");
        exit(-1);
    }

    int l = 0;
    int r = len - 1;
    MSort(arr, tmpArr, l, r);

    free(tmpArr);
}
