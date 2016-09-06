/*************************************************************************
	> File Name: power.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月06日 星期二 20时35分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int isEven(int val) {
    if (val == 0)
        return 1;
    else if (val == 1)
        return 0;
    else
        return (val%2 == 0);
}

int power(int x, int n) {
    if (n == 0)
        return 1;

    int p;
    if (isEven(n)) {
        p = power(x, n/2);
        return p * p;
    } else {
        p = power(x, (n-1)/2);
        return x * p * p;
    }
} 
