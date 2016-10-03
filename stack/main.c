#include <stdio.h>

#include "stack.h"

void test() {
	int i;
	int minSize = 12;	
	stack s = createStack(minSize);
	
	for (i = 0; i < minSize; i++) {
		push(s, i);
	}

	for ( i = 0; i <= minSize; i++) {
		int data = topAndPop(s);

		printf("data:%d\n", data);
	}
	
}

int main() {
	test();
	return 0;
}
