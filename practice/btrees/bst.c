#include <stdio.h>
#include "bst.h"
#include <queue>
using namespace std;


void BST::insertIteratively(int val){
  if(m_root == NULL){
    m_root = new Node(val);
    return;
  }
  Node* cur = m_root;

  while(true){
    if(val == cur->m_val) return; //already in bst

    else if (val < cur->m_val){
      if(cur->left == NULL){
	cur->left = new Node(val);
	return;
      }
      else{
	cur = cur->left;
      }
    }

    else{
      if(cur->right == NULL){
	cur->right = new Node(val);
	return;
      }
      else cur = cur->right;
    }

  }

}

void BST::inorderEnumerate(Node* cur){
  if(cur == NULL)
    return;
  inorderEnumerate(cur->left);
  printf("%d ", cur->m_val);
  inorderEnumerate(cur->right);
}

void BST::postorderEnumerate(Node* cur){
  if(cur == NULL)
    return;
  postorderEnumerate(cur->left);
  postorderEnumerate(cur->right);
  printf("%d ", cur->m_val);

}

void BST::preorderEnumerate(Node* cur){

  if(cur == NULL)
    return;
  printf("%d ", cur->m_val);
  preorderEnumerate(cur->left);
  preorderEnumerate(cur->right);

}


void BST::levelorderEnumerate(Node* cur){
  queue<Node*> line;
  if(cur == NULL)
    return;
  
  line.push(cur);
  
  while(!line.empty()){
    Node* top = line.front();
    printf("%d ", top->m_val);
    if(top->left != NULL)
      line.push(top->left);
    if(top->right != NULL)
      line.push(top->right);
    line.pop();
  }
  return;
}


bool BST::searchBST(const int& val, Node* cur){
  if(cur == NULL)
    return false;
  else if(cur->m_val == val)
    return true;
  else if(val < cur->m_val)
    return searchBST(val, cur->left);
  else
    return searchBST(val, cur->right);
}

void BST::freeTree(Node* cur){
  if(cur == NULL)
    return;
  freeTree(cur->left);
  freeTree(cur->right);
  delete cur;

}

bool BST::deleteNode(const int& val, Node* root){
  /*step1. Find val*/
  Node* parent = NULL;
  Node* cur = root;
  while(cur != NULL){
    if(cur->m_val == val){
      /*case 1: if val is at leaf node*/
      if(cur->left == NULL && cur->right == NULL)
	return deleteLeaf(val, parent, cur);
      
      else if((cur->left == NULL && cur->right != NULL) || (cur->left != NULL && cur->right == NULL))
	return deleteSingleChildNode(val, parent, cur);

    }
    else if(val < cur->m_val){
      parent = cur;
      cur = cur->left;
    }
    else{
      parent = cur;
      cur = cur->right;
    }

  }
  return false; //val not in bst

}

bool BST::deleteLeaf(int val, Node* parent, Node* cur){

  if(parent == NULL)
    m_root = NULL;

  else if(cur == parent->left)
    parent->left = NULL;

  else
    parent->right = NULL;

  delete cur;
  return true;
}

bool BST::deleteSingleChildNode(int val, Node* parent, Node* cur){
  if(parent == NULL)
    m_root = cur->left == NULL?cur->right:cur->left;

  else if(cur == parent->left)
    parent->left = cur->left == NULL?cur->right:cur->left;

  else if(cur == parent->right)
    parent->right = cur->left == NULL?cur->right:cur->left;

  delete cur;
  return true;
}
