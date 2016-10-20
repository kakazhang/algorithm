#include <stdio.h>

#include "binaryHeap.h"

void testBHeap() {
	pBHeap heap = initHeap(24, 0);

	Insert(heap, 3);
	Insert(heap, 1024);
	Insert(heap, 108);
	Insert(heap, 94);
	Insert(heap, 87);
	Insert(heap, 87);

	int min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);
	min = DeleteMin(heap);
	printf("min:%d\n",min);

	makeEmpty(heap);
}

int main() {
	testBHeap();
	return 0;
}
