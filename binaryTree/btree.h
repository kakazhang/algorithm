/*************************************************************************
	> File Name: btree.h
	> Author: 
	> Mail: 
	> Created Time: 2016年09月26日 星期一 13时31分23秒
 ************************************************************************/

#ifndef _BTREE_H
#define _BTREE_H
typedef struct BTree {
    int data;
    struct BTree *left;
    struct BTree *right;
} BTree,*pTree, *pNode;

pNode FindMin(pTree root);

pNode FindMax(pTree root);

pNode Insert(pTree root, int data);

pNode Delete(pTree root, int data);

void preTraversal(pTree root);

void inOrderTraversal(pTree root);

pNode Search(pTree root, int data);

int getLeafCount(pTree root);

int height(pTree root);

int isBST(pTree root);
#endif
