#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void test() {
	Queue Q = createQueue(12);

	int i;
	for (i = 0; i < 16; i++) {
		enqueue(Q, i);
	}

	for (i = 0; i < 16; i++) {
		int value = dequeue(Q);
		printf("value:%d\n", value);
	}

	deposeQueue(Q);
}

int main() {
	test();

	return 0;
}
