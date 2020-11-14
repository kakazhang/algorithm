#ifndef QUEUE_H
#define QUEUE_H
#define MINSIZE 1024

typedef struct {
    int data_len;
    char *buf;
} UsbData;

typedef struct queue {
	int front;
	int rear;
	int size;
	int capacity;
	UsbData **usb_datas;
} *Queue;

int isEmpty(Queue Q);

int isFull(Queue Q);

void makeEmpty(Queue Q);

void enqueue(Queue Q, UsbData* data);

UsbData* dequeue(Queue Q);

Queue createQueue(int minSize) ;

void deposeQueue(Queue Q);
#endif
