/*************************************************************************
	> File Name: fabonacci.c
	> Author: 
	> Mail: 
	> Created Time: 2016年11月16日 星期三 21时24分44秒
    >Description:given a number n,find the nth even fabonacci number
 ************************************************************************/
#include <stdio.h>
/**
*use iteration algorithm to optimize recursion algorithm
* */
int optimise(unsigned int n) {
    int i;
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for (i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int fabonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fabonacci(n-2) + fabonacci(n-1);
}

int get_even_number(int n) {
    int index = 3 * n;

    //return fabonacci(index);
    return optimise(index);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("please input a number\n");
        return -1;
    }

    int n = atoi(argv[1]);

    int number = get_even_number(n);
    printf("%d th number is %d\n", n, number);

    return 0;
}
