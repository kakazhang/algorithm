#ifndef BINARYHEAP_H
#define BINARYHEAP_H

typedef struct bheap {
    int *array;
	int size;
	int capacity;
} BHeap, *pBHeap;

int isEmpty(pBHeap heap);

int isFull(pBHeap heap);

int findMin(pBHeap heap);

pBHeap initHeap(int minCapacity, int minData);

void Insert(pBHeap heap, int data);

int DeleteMin(pBHeap heap);

void makeEmpty(pBHeap heap);
#endif