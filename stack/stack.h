#ifndef STACK_H
#define STACK_H

#define TOP_INVALID -1
#define MINMUM 12

typedef struct stack{
	int *array;
	int topIndex;
	int maxSize;
} *stack;

int isEmpty(stack s);

int isFull(stack s);

void makeEmpty(stack s);

void push(stack s, int data);

void pop(stack s);

int topAndPop(stack s);

stack createStack(int maxSize);
#endif
