#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void show2Smallest(int arr[], int len) {
    int first = INT_MAX;
    int second = INT_MAX;

    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MAX) {
        printf("no two smallest\n");
    } else {
        printf("smallest first:%d, second:%d\n", first, second);
    }
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    show2Smallest(arr, n);

    return 0;
}

