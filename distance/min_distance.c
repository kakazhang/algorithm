/*************************************************************************
	> File Name: min_distance.c
	> Author:zhanglin 
	> Mail: zhanglin3406@gmail.com
	> Created Time: 2016年12月11日 星期日 16时34分32秒
    >>>>>>>
    > Given an array of n elements, find the minmum distance between two 
    > different elements
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_distance(int arr[], int len, int x, int y) {
    int i;
    int prev;
    int min_dis = INT_MAX;

    for (i = 0; i < len; i++) {
        if (x == arr[i] || y == arr[i]) {
            prev = i;
            break;
        }
    }

    for (; i < len; i++) {
        if (arr[i] == x || arr[i] == y) {
            if (arr[i] != arr[prev] && (i-prev) < min_dis) 
                min_dis = i-prev;
            
            prev = i;
        }
    }

    return min_dis;
}

int main() {
    int arr[] = {3, 5, 4, 2, 6, 3, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 2;

    printf("Minimum distance between %d and %d is %d\n", x, y, 
           min_distance(arr, n, x, y));

    return 0;
}
