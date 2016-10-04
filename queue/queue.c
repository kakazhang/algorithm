#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int isEmpty(Queue Q) {
	return Q->size == 0;
}

int isFull(Queue Q) {
	return Q->size == Q->capacity;
}

void makeEmpty(Queue Q) {
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
}

static int succ(Queue Q, int value) {
    if (++value == Q->capacity)
		value = 0;

	return value;
}

void enqueue(Queue Q, int value) {
	if (isFull(Q)) {
		printf("Queue is full with enqueue :%d\n", value);
		return;
	}

	Q->size++;
	Q->array[Q->rear] = value;
	Q->rear = succ(Q, Q->rear);
}

int dequeue(Queue Q) {
	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		return -1;
	}

	Q->size--;

	int value = Q->array[Q->front];
	Q->front = succ(Q, Q->front);

	return value;
}

Queue createQueue(int minSize) {
	if (minSize < MINSIZE)
		minSize = MINSIZE;

	Queue Q = (Queue)malloc(sizeof(Queue));
	if (!Q) {
		printf("no space\n");
		exit(-1);
	}

	makeEmpty(Q);
	Q->capacity = minSize;
	Q->array = (int *)malloc(sizeof(int) * Q->capacity);
	if (NULL == Q->array) {
		free(Q);
		printf("No space\n");
		exit(-1);
	}
	
	return Q;
}

void deposeQueue(Queue Q) {
	if (Q) {
		free(Q->array);

		free(Q);
	}
}
