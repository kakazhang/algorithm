/*************************************************************************
	> File Name: pair_wise.c
	> Author: 
	> Mail: 
	> Created Time: 2016年11月07日 星期一 16时29分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Pos, *pNode;

static void assert(int cond, const char* msg) {
    if (!cond) {
        printf("%s\n", msg);
        exit(-1);
    }
}

static pNode alloc(int data) {
    pNode node = (pNode)malloc(sizeof(Pos));
    assert((node != NULL), "no space for node");

    node->data = data;
    node->next = NULL;
    return node;
}

static void list_init(pNode *root, int data) {
    *root = alloc(data);
}

static void list_add(pNode* root, int data) {
    pNode newnode = alloc(data);

    newnode->next = *root;
    *root = newnode;
}

static void list_removeall(pNode root) {
    if (root) {
        list_removeall(root->next);
        printf("freeing:%d\n", root->data);
        free(root);
    }
}

static void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

static void show(pNode root) {
    while (root) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
} 

static void pair_wise(pNode *root) {
    pNode tmp = *root;

    pNode prev = *root;
    pNode curr = prev->next;

    show(tmp);
    while (prev != NULL && curr != NULL) {
        swap(&prev->data, &curr->data);
        prev = curr->next;
        if (prev)
            curr = prev->next;
        
    }

    show(tmp);
}

int main() {
    pNode root;
    list_init(&root, 5);
    list_add(&root, 21);
    list_add(&root, 8);
    list_add(&root, 4);
    list_add(&root, 12);

    pair_wise(&root);

    list_removeall(root);

    return 0;
}
