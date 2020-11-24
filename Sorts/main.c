#include <stdio.h>

extern void insertionSort(int arr[], int len);
extern void shellSort(int arr[], int len);
extern void bubble(int arr[], int len);
extern void MergeSort(int arr[], int len);

void show(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int arr[] = {3, 18, 5, 4, 96};
    int len = sizeof(arr)/sizeof(arr[0]);

    show(arr, len);
    //printf("insertionSort:\n");
    //insertionSort(arr, len);
    //show(arr, len);

    printf("Sort:\n");
    //shellSort(arr, len);
    //bubble(arr, len);
    MergeSort(arr, len);
    show(arr, len);

    return 0;
}
