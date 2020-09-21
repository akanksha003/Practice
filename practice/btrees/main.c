#include <stdio.h>
#include "bst.h"
using namespace std;

int main(int argc, char** argv){

  BST tree;
  tree.insertIteratively(2);
  tree.insertIteratively(1);
  tree.insertIteratively(4);
  tree.insertIteratively(3);
  Node* root = tree.getRoot();

  int x = 3;
  tree.deleteNode(x,root);
  
  if(tree.searchBST(x, root))
    printf("found!\n");
  else
    printf("not found!\n");

  
  printf("in-order: ");
  tree.inorderEnumerate(root);
  printf("\n");
  
  printf("post-order: ");
  tree.postorderEnumerate(root);
  printf("\n");

  printf("pre-order: ");
  tree.preorderEnumerate(root);
  printf("\n");

  printf("level-order: ");
  tree.levelorderEnumerate(root);
  printf("\n");
  
  printf("Success!\n");
  return 0;
}
