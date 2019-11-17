/*************************************************************************
	> File Name: euclid.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月02日 星期日 23时14分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int change(int* x, int* y) {
    int tmp = *x;
	*x = *y;
	*y = tmp;

	return 0;
}

int gcd(int x, int y) {
    while (x != y) {
       if(x > y) 
          x = x - y;
       else
            y = y - x;
    }

    return y;
}


int euclid(int x, int y) {
	int r;
    if (y > x) 
        change(&x, &y);

	r = x % y;
	if (r == 0) 
        return y;

    x = y;
    y = r;

	return euclid(x, y);
}

int main(int argc, char** argv) {
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("gcd(%d,%d)=%d\n", x, y, gcd(x,y));
    printf("gcd(%d,%d)=%d\n", x, y, euclid(x,y));

    return 0;
}
