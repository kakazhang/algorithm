/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月06日 星期二 20时42分35秒
 ************************************************************************/

#include<stdio.h>

#define N 5

extern int power(int x, unsigned n);

void test_power() {
    int i;
    for (i = 0; i < N; i++) {
        printf("power(5,%d), %d\n", i, power(5, i));
    }
}

int main() {
    test_power();
    return 0;
}
