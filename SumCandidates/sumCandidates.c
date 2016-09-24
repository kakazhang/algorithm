/*************************************************************************
	> File Name: sumCandidates.c
	> Author: kakazhang
	> Mail: kakazhang@gmail.com
	> Created Time: 2016年09月07日 星期三 18时43分57秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void* b) {
    const int *pa = (int *)a;
    const int *pb = (int *)b;

    if (a < b) return -1;
    if (a > b) return 1;

    return 0;
}

int hasSumCandidates(int array[], int len, int sum) {
    qsort(array, len, sizeof(array[0]), cmp);

    int l = 0;
    int h = len -1;

    while (l < h) {
        if (array[l] + array[h] == sum) 
            return 1;
        else if (array[l] + array[h] < sum)
            l++;
        else 
            h--;
    }

    return 0;
}

int main() {
    int array[] = {2, 0, 12, 3, 9, 11};
    int len = sizeof(array)/sizeof(array[0]);

    int sum = 15;

    printf("hasSumCandidates:%d\n", hasSumCandidates(array, len, sum));

    return 0;
}
