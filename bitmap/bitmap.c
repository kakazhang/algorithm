#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"

#define N 10000

long arr[1+N/BITSPERLONG] = {0};

void set(int i) {
   arr[i/BITSPERLONG] |= (1 << (i & BITMAPMASK));
}

void clear(int i) {
	arr[i/BITSPERLONG] &= ~(1 << (i & BITMAPMASK));
}

int test(int i) {
    return arr[i/BITSPERLONG] & (1 << (i & BITMAPMASK));
}

int getzeroleft(unsigned int a) {
    return __builtin_clz(a);
}

int getzeroright(unsigned int a) {
    return __builtin_ctz(a);
}
