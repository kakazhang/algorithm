/**
*牛顿-拉弗森 (又称巴比伦方法)方法求sqrt
* */

#include <stdio.h>
#include <math.h>
float babylonian(int n) {
    float x = n;
    float y = 1;

    float e = 0.000001;

    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }

    return x;
}

int findMaxHeight(int N) {
    int n = 8*N + 1;
    int maxHeight = (-1 + babylonian(n)) / 2;
    
    return maxHeight;
}

int main(int argc, char** argv) {
    int n = atoi(argv[1]);

    float square = babylonian(n);

    printf("sqrt(%d) = %f\n", n, square);
    
    int maxHeight = findMaxHeight(n);
    printf("maxHeight = %d\n", maxHeight);

    return 0;
}
