#include <stdio.h>
#include <stdlib.h>
#include "oneway_linklist.h"

pNode gNode = NULL;

pNode NewNode(int val) {
    pNode node = (pNode)malloc(sizeof(Node));
	if (node == NULL) {
	    printf("no memory for new node\n");
		exit(-1);
	}

	node->val = val;
	node->next = NULL;
}

void DeleteNode(pNode node) {
    if (node != NULL) {
	    free(node);
	}
}

void init(int N) {
    int i;
    pNode node = NULL;
    pNode last = NULL;
	for (i = 0; i < N; i++) {
	    node = NewNode(i);
        if (gNode == NULL)
            gNode = node;
        if (last != NULL)
		    last->next = node;
		last = node;
	}
}

void destroy() {
    pNode node = gNode;
    pNode next = NULL;
	while (node) {
	    next = node->next;
		free(node);
		node = next;
	}
}

void iterate(pNode node) {
    while (node) {
	    printf("node:%d\n", node->val);
		node = node->next;
	}
}

void reverse() {
    pNode pCur = gNode;
	pNode prev = NULL;
	pNode pNext = pCur->next;

	while (pCur && pNext) {
	    pCur->next = prev;

		prev = pCur;
		pCur = pNext;
		pNext = pNext->next;
	}

	if (pCur) {
		pCur->next = prev;
	    gNode = pCur;
	}
}

int main(int argc, char** argv) {
    init(5);

	iterate(gNode);
	printf("\n");
    reverse();
	iterate(gNode);

	destroy();

	return 0;
}
