#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"

void testBitmap() {
    set(10);
	printf("test(%d):0x%x\n", 10, test(10));

	clear(10);
	printf("test(%d):0x%x\n", 10, test(10));
}

void test_builtin() {
    unsigned int a = 1;

    printf("0 count before %x:%d\n", a, getzeroleft(a));
    
    a = 2;
    printf("0 count after %x: %d\n", a, getzeroright(a));

    printf("first 1 right of %d :%d\n", a, __builtin_ffs(a));
}

int main() {
	testBitmap();

    test_builtin();
	return 0;
}
