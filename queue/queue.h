#ifndef QUEUE_H
#define QUEUE_H
#define MINSIZE 12

typedef struct queue {
	int front;
	int rear;
	int size;
	int capacity;
	int *array;
} *Queue;

int isEmpty(Queue Q);

int isFull(Queue Q);

void makeEmpty(Queue Q);

void enqueue(Queue Q, int value);

int dequeue(Queue Q);

Queue createQueue(int minSize) ;

void deposeQueue(Queue Q);	
#endif
