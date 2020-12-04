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

void enqueue(Queue Q, UsbData *udata) {
    if (isFull(Q)) {
	printf("Queue is full\n");
	return;
    }

    Q->size++;
    Q->usb_datas[Q->rear] = udata;
    Q->rear = succ(Q, Q->rear);
}

UsbData* dequeue(Queue Q) {
	if (isEmpty(Q)) {
	    printf("Queue is empty\n");
	    return NULL;
	}

	Q->size--;

	UsbData* udata = Q->usb_datas[Q->front];
	Q->front = succ(Q, Q->front);

	return udata;
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
    Q->usb_datas = (UsbData **)malloc(sizeof(UsbData*) * Q->capacity);
    if (NULL == Q->usb_datas) {
	free(Q);
	printf("No space for queue data\n");
	exit(-1);
    }

    return Q;
}

void deposeQueue(Queue Q) {
    if (Q) {
	free(Q->usb_datas);

	free(Q);
    }
}
