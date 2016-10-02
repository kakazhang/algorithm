/*************************************************************************
	> File Name: euclid.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月02日 星期日 23时14分58秒
 ************************************************************************/

#include <stdio.h>

int gcd(int x, int y) {
    while (x != y) {
       if(x > y) 
          x = x - y;
       else
            y = y - x;
    }

    return y;
}

int main(int argc, char** argv) {
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("gcd(%d,%d)=%d\n", x, y, gcd(x,y));

    return 0;
}
