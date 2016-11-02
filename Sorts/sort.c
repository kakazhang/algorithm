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
