/*************************************************************************
	> File Name: maxSum.c
	> Author: zhanglin
	> Mail: zhanglin3406@gmail.com
	> Created Time: 2016年10月04日 星期二 15时32分51秒
   
   Given an array of positive elements, find the maximum sum of a subsequence with the constraint that 
   no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should    
   return 15 (sum of 3, 5 and 7).Answer the question in most efficient way. 

************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int findMaxSum(int arr[], int len) {
    int exc = 0;
    int inc = arr[0];
    int exc_new;

    int i;
    for (i = 1; i < len; i++) {
        exc_new = max(exc, inc);

        inc = exc + arr[i];
        exc = exc_new;
    }

    return max(exc, inc);
}

int main() {
    //int arr[] = {5, 5, 10, 40, 50, 35};
    int arr[] = {3, 10, 2, 8};
    
    int len = sizeof(arr)/sizeof(arr[0]);

    int sum = findMaxSum(arr, len);

    printf("maxSum:%d\n", sum);

    return 0;
}
