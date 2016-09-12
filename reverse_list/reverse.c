/*************************************************************************
	> File Name: reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月12日 星期一 16时19分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 16

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

void show_in_seq(pNode node) {
    pNode p = node;

    while (p) {
        printf("%d\n", p->val);
        p = p->next;
    }
}

void reverse() {
    pNode prev = NULL;
    pNode curr = root;
    pNode next = curr->next;

    while (curr && next) {
        //set next node of current to prev
        curr->next = prev;

        prev = curr;
        curr = next;

        next = curr->next;
    }

    curr->next = prev;

    root = curr;
}

int main() {
    show_in_seq(root);

    reverse();
    printf("reversed:\n");

    show_in_seq(root);

    return 0;
}
