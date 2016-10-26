#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int num_cmp(const void* _a, const void* _b) {
    const int *pa = _a;
    const int *pb = _b;

    if (*pa < *pb)
        return -1;
    else if (*pa > *pb)
        return 1;
    else
        return 0;
}

int minAbsSum(int arr[], int len) {
    int l = 0, r = len -1;
    int min_l = 0, min_r = 0;

    int sum = 0;
    int minSum = INT_MAX;

    while (l < r) {
        sum = arr[l] + arr[r];

        if (abs(sum) < abs(minSum)) {
            min_l = l;
            min_r = r;
            minSum = sum;
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    return minSum;
}

int main() {
    int arr[] = {-10, 2, 9, -2, 8};
    int len = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, len, sizeof(int), num_cmp);

    int minSum = minAbsSum(arr, len);

    printf("minSum:%d\n", minSum);

    return 0;
}
