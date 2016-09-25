/*************************************************************************
	> File Name: transfer.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月24日 星期六 23时04分21秒
 ************************************************************************/

#include<stdio.h>


int count_bits(int a) {
    int count = 0;

    while (a) {
        count += a & 1;
        a >>= 1;
    }

    return count;
}

int count_transfer_bits(int a, int b) {
    int c = a ^ b;

    return count_bits(c);
}

int main(int argc, char** argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("bits:%d\n", count_transfer_bits(a,b));

    return 0;
}
