/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年09月06日 星期二 14时25分51秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define N 10

typedef struct cache {
    int size;
    Position node;
}Cache, *pCache;

Position root;

static void assert(int cond, const char* msg) {
    if (!cond) {
        printf("%s\n", msg);
        exit(-1);
    }
}

void test_cache() {
    int i;

    list_init(&root);

    for (i = 0; i < N; i++) {
        pCache pc = (pCache)malloc(sizeof(Cache));
        assert((pc != NULL), "No space for cache");

        pc->size = i;
        list_add_tail(&root, &(pc->node));
    }

    pNode p;
    list_for_each(&root, p) {
       pCache pc = contains(p, Cache, node);
       printf("item:%d\n", pc->size);
    }

    //remove every node
    pNode n;
    list_for_each_safe(&root, p, n) {
        pCache pc = contains(p, Cache, node);
        
        list_del(p);
        free(pc);
    }
}

int main() {
    test_cache();

    return 0;
}
