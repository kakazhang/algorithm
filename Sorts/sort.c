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
#ifdef MERGE_ITERACTE
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
#else
int min(int a, int b)
{
    return a < b ? a : b;
}

void MergeSort(int arr[], int len)
{
    int seg, start;

    int *a = arr;
    int *b = (int *)malloc(sizeof(int) * len);

    for (seg = 1; seg < len; seg += seg) {
        int k = 0;
        for (start = 0; start < len; start += 2*seg) {
            int low = start;
            int mid = min(start + seg, len);
            int high = min(start + 2*seg, len);

            int start1 = low;
            int end1 = mid;
            int start2 = mid;
            int end2 = high;

            while (start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }

            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *tmp = a;
        a = b;
        b = tmp;
    }

    int i = 0;
    if (a != arr) {
        while (i < len) {
            b[i] = a[i];
            i++;
        }
        b = a;
    }
    free(b);
}
#endif
