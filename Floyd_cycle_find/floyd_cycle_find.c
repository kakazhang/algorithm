#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *pNode;

void push(pNode *head, int val) {
    pNode newNode = (pNode)malloc(sizeof(Node));
    if (!newNode) {
        printf("no space\n");
        exit(-1);
    }

    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

int detectLoop(pNode head) {
    pNode slow = head;
    pNode fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) 
        return 1;
    }

    return 0;
}

int main() {
    pNode head = NULL;

    push(&head, 3);
    push(&head, 22);
    push(&head, 109);
    push(&head, 32);

    head->next->next->next->next = head;

    int found = detectLoop(head);

    printf("found:%d\n", found);

    return 0;
}
