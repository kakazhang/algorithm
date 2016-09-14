/*************************************************************************
	> File Name: fastway_to_delete_singlelinklist_node.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月14日 星期三 15时39分45秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Position, *pNode;

pNode alloc_node(int val) {
    pNode node = (pNode)malloc(sizeof(Position));
    if (!node) {
        printf("no space\n");
        exit(-1);
    }

    node->val = val;
    node->next = NULL;

    return node;
}

void list_add(pNode *root, int val) {
    pNode node = alloc_node(val);
    
    node->next = *root;
    *root = node;
}

void list_remove(pNode node) {
    pNode tmp = node->next;
    if (tmp) {
        node->val = tmp->val;
        node->next = tmp->next;
        free(tmp);
    } else if(node) {
        free(node);
    }
}

void test() {
    int i;
    pNode root = NULL;
    for (i = 0; i < 10; i++) {
        list_add(&root, i);
    }
    
    pNode p = root;
    pNode found = NULL;
    while (p) {
        printf("val:%d\n", p->val);
        if (p->val == 4)
            found = p;

        p = p->next;
    }

    printf("------------------------\n");
    list_remove(found);
    p = root;
    while (p) {
        pNode tmp = p;
        printf("val:%d\n", p->val);

        p = p->next;
        free(tmp);
    }
}

int main() {
    test();
    return 0;
}
