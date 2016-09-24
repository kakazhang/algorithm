/*************************************************************************
	> File Name: panlindrom.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月24日 星期六 20时58分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *pNode;

void push(pNode* head, int data) {
    pNode newNode = (pNode)malloc(sizeof(Node));
    if (!newNode) {
        printf("No space\n");
        exit(-1);
    }

    newNode->data = data;

    newNode->next = *head;
    *head = newNode;
}

int isPanlindrome(pNode head) {
    pNode ptr = head;

    pNode slow = head;
    pNode fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;

        fast = fast->next->next;
    }

    pNode mid = NULL;
    if (!fast) {
        mid = slow;
    } else {
        mid = slow->next;
    }
    
    pNode prev = NULL;
    pNode curr = mid;
    pNode next = curr->next;
    while (curr && next) {
        curr->next = prev;

        prev = curr;
        curr = next;
        next = next->next;
    }

    while (curr) {
        if (curr->data != ptr->data) 
            return 0;

        curr = curr->next;
        ptr = ptr->next;
    }

    return 1;
}

int main() {
    pNode head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);

    printf("isPanlindrome:%d\n", isPanlindrome(head));

    return 0;
}
