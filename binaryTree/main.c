#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

int main() {
   pTree root = NULL;
   
   root = Insert(root, 30);
   Insert(root, 19);
   Insert(root, 45);
   Insert(root, 50);
   Insert(root, 21);
   Insert(root, 32);
   Insert(root, 40);
   Insert(root, 5);

   preTraversal(root);

   printf("height:%d\n", height(root));

  pNode found = Search(root, 42);
  if (found)
      printf("found:%d\n", found->data);
  else 
      printf("not found\n");

  int leaves = getLeafCount(root);
  printf("leaves:%d\n", leaves);

  printf("after delete\n");
  Delete(root, 32);
  preTraversal(root);
  printf("height:%d\n", height(root));
  return 0;
}
