/*************************************************************************
	> File Name: leader.c
	> Created Time: 2016年10月06日 星期四 13时41分39秒
  Print all leader in an array.An element is leader if it is bigger than
  all ones else
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void printLeader(int array[], int len) {
    int i;
    int max_from_right = array[len-1];
    printf("leader:%d\n", max_from_right);

    for (i = len-2; i >= 0; i--) {
        if (max_from_right < array[i]) {
            printf("leader:%d\n", array[i]);
            max_from_right = array[i];
        }
    }
}

int main() {
    int array[] = {16, 17, 4, 3, 5, 2};
    int len = sizeof(array)/sizeof(array[0]);

    printLeader(array, len);

    return 0;
}
