#include <stdio.h>
#include <stdlib.h>

#include "binaryHeap.h"

#define MINCAPACITY 24

static void assert(int cond, const char* msg) {
	if (!cond) {
		printf("%s\n",msg);
		exit(-1);
	}
}

int isEmpty(pBHeap heap) {
	assert(heap != NULL, "Heap is not initialized");

	return (heap->size == 0);
}

int isFull(pBHeap heap) {
	assert(heap != NULL, "Heap is not initialized");

	return (heap->size == heap->capacity);

}

int findMin(pBHeap heap) {
	assert(heap != NULL, "Heap is not initialized");
	if (isEmpty(heap))
			return heap->array[0];

	return heap->array[1];
}

pBHeap initHeap(int minCapacity, int minData) {
	if (minCapacity < MINCAPACITY)
		minCapacity = MINCAPACITY;
	
	pBHeap heap = (pBHeap)malloc(sizeof(BHeap));
	assert((heap != NULL), "No space for BHeap");
	
	heap->capacity = minCapacity;
	heap->size = 0;
	
	heap->array = (int *)malloc(sizeof(int) * (heap->capacity + 1));
	assert((heap != NULL), "No space for array int BHeap");

	return heap;
}

/**
* @parent and child :left child = parent * 2 ,right child = parent * 2 + 1
*/
void Insert(pBHeap heap, int data) {
	if (isFull(heap))
		return;

	int i;
	for (i = ++heap->size; heap->array[i/2] > data; i /= 2) 
		heap->array[i] = heap->array[i/2];

	heap->array[i] = data;
}

int DeleteMin(pBHeap heap) {
	int min = findMin(heap);
	if (isEmpty(heap))
		return min;
	int last = heap->array[heap->size--];

	int i;
	for ( i = 1; 2*i <= heap->size; ) {
		int child = 2 * i;

		if (child != heap->size && heap->array[child] > heap->array[child+1])
			child++;

		if (heap->array[child] < last) {
			heap->array[i] = heap->array[child];
		} else {
			break;
		}

		i = child;
	}

	heap->array[i] = last;
	return min;
}

void makeEmpty(pBHeap heap) {
	if (heap) {
		if (heap->array)
			free(heap->array);

		free(heap);
	}
}

