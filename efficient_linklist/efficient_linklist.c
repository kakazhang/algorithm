/*************************************************************************
	> File Name: efficient_linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月19日 星期一 22时17分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node *tail = NULL;

Node* allocNode(int data) {
    Node* node = (Node *)malloc(sizeof(Node));
    if (!node) {
        printf("No space\n");
        exit(-1);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void freeAll() {
    Node *prev = NULL;
    Node *curr = head;
    Node *tmp;
    
    while (curr) {
        tmp = curr;
        curr = (Node *)((unsigned int)prev ^ (unsigned int)curr->next);
        prev = tmp;
         
        free(tmp);
    }
}

void insert(int data) {
    Node* ptr = allocNode(data);

    if (!head) {
        head = ptr;
        tail = ptr;

        return;
    }

    ptr->next = tail;
    tail->next = (Node*)((unsigned int)ptr ^ (unsigned int)tail->next);
    tail = ptr;
}

void show(Node *node) {
    Node* prev = NULL;
    Node* cur = node;
    Node* next = NULL;

    while (cur) {
        printf("data:%d\n",cur->data);

        next = (Node*)((unsigned int)prev ^(unsigned int)cur->next );
        prev = cur;
        cur = next;
    }
}

int main() {
    insert(2);
    insert(4);
    insert(24);

    show(head);

    freeAll();
    return 0;
}
