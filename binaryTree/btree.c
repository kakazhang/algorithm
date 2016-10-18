#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

pNode allocNode(int data) {
    pNode newNode = (pNode)malloc(sizeof(BTree));
    if (!newNode) {
        printf("no space\n");
        exit(-1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

pNode FindMin(pTree root) {
    //check illegal input argument
    if (!root)
        return NULL;
    
    pNode n = root;
    while (n && n->left) {
        n = n->left;
    }

    return n;
}

pNode FindMax(pTree root) {
    //check illegal input arguments
    if (!root)
        return NULL;

    pNode n = root;
    while (n && n->right) {
        n = n->right;
    }

    return n;
}

pNode Insert(pTree root, int data) {
    if (!root) {
        root = allocNode(data);
        return root;
    }   

    if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    
    return root;
}

pNode Delete(pTree root, int data) {
    if (!root)
        return NULL;

    pNode tmp = NULL;
    if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        if (root->left && root->right) {
            tmp = FindMin(root->right);
            root->data = tmp->data;

            root->right = Delete(root->right, tmp->data);
        } else {
            tmp = root;
              
            if (root->left == NULL) 
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            
            free(tmp);
        }
    }

    return root;
}

#if 1 
int getLeafCount(pTree node) {
    if (!node)
        return 0;

    if ((node->left == NULL) && (node->right == NULL))
        return 1;

    return getLeafCount(node->left) + getLeafCount(node->right);
}
#else 
int getLeafCount(pTree node) {
    static int count = 0;
    if (!node)
        return 0;
    if (node->left == NULL && node->right == NULL)
        count++;

    getLeafCount(node->left);
    getLeafCount(node->right);

    return count;
}
#endif

pNode Search(pTree root, int data) {
    if (!root)
       return NULL;

    if (data < root->data) 
        return  Search(root->left, data);
    else if (data > root->data)
        return  Search(root->right, data);
    else
        return root;
}

void preTraversal(pTree root) {
    if (root) {
	printf("%d\n", root->data);
        preTraversal(root->left);
        preTraversal(root->right);
    }
}

void inOrderTraversal(pTree root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d\n", root->data);
        inOrderTraversal(root->right);
    }
}

int height(pTree root) {
    if (!root)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return MAX(lheight, rheight) + 1;
}

int isBST(pTree root) {
    static pTree prev = NULL;

    if (!root)
        return 1;

    if (!isBST(root->left))
        return 0;

    if (prev && root->data < prev->data)
        return 0;

    prev = root;

    return isBST(root->right);
}
