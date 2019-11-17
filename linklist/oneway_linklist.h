#ifndef ONEWAY_LINK_LIST_H
#define ONEWAY_LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node {
    int val;
	struct Node* next;
} Node, *pNode;


pNode NewNode(int val);

void DeleteNode(pNode node);

#ifdef __cplusplus
}
#endif
#endif
