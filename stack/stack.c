#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
int isEmpty(stack s) {
	return s->topIndex == TOP_INVALID;
}

int isFull(stack s) {
	return (s->topIndex == s->maxSize);
}

void makeEmpty(stack s) {
	if (s) {
		s->topIndex = TOP_INVALID;
	}
}

void push(stack s, int data) {
	if (isFull(s)) {
		printf("stack is full\n");
		return;
	}

	s->array[s->topIndex++] = data;
}

void pop(stack s) {
	if (isEmpty(s)) {
		printf("stack is empty\n");
		return;
	}
	
	s->topIndex--;
}

int topAndPop(stack s) {
	if (isEmpty(s)) {
		printf("stack is empty\n");
		return 0;
	}

	return s->array[--s->topIndex];
}

stack createStack(int maxSize) {
	if (maxSize < MINMUM) {
		maxSize = MINMUM;
	}
	stack s = (stack)malloc(sizeof(struct stack));
	if (!s) {
		perror("malloc");
		return NULL;
	}

	s->maxSize = maxSize;
	s->array = (int *)malloc(sizeof(int) * s->maxSize);
	if (s->array == NULL) {
		free(s);
		perror("malloc");
		return NULL;
	}

	makeEmpty(s);
	

	return s;
}

void deposStack(stack s) {
	if (s) {
		free(s->array);
		free(s);
	}
}
