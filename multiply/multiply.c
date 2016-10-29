#include <stdio.h>

int multiply(int x, int y) {
    if (y == 0)
        return 0;

    if (y > 0) 
        return x + multiply(x, y-1);
    else 
        return -multiply(x, -y);
}

int main(int argc, char** argv) {
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("multiply(%d,%d) = %d\n", x, y, multiply(x,y));

    return 0;
}

