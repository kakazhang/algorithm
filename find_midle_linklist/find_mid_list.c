/*************************************************************************
	> File Name: find_mid_list.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月12日 星期一 15时49分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Node {
    int val;
    struct Node *next;
} Position, *pNode;

static pNode newNode(int val) {
    pNode node = (pNode)malloc(sizeof(Position));
    if (NULL == node) {
        printf("no space\n");
        exit(-1);
    }

    node->val = val;
    return node;
}

static pNode root = NULL;

static void __attribute__((constructor)) init() {
    int i;
    for (i = 0; i < N; i++) {
        pNode pn = newNode(i);
        if (root == NULL) {
            root = pn;
        } else {
            pn->next = root;
            root = pn;
        }
    }
}

static void __attribute__((destructor)) destroy() {
    pNode p = root;
    pNode tmp;
    while (p) {
        tmp = p;
        p = p->next;

        free(tmp);
    }
}

pNode find_mid_list() {
    pNode fast = root;
    pNode slow = root;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    pNode pn = find_mid_list();
    printf("mid:%d\n", pn->val);

    return 0;
}
