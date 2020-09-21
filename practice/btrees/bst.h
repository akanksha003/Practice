#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <unistd.h>
using namespace std;

struct Node{
  Node(const int& value){
    m_val = value; value;
    left = NULL;
    right = NULL;
  }
  int m_val;
  Node* left;
  Node* right;
};


class BST{
 public:
  BST(){m_root = NULL;}

  Node* getRoot(){return m_root;}
  
  /*delete operations*/
  void freeTree(Node* cur);
  bool deleteNode(const int& val, Node* root);

  /*adding*/
  void insertIteratively(int val);

  /*enumerating in different ways*/
  void inorderEnumerate(Node* cur);
  void postorderEnumerate(Node* cur);
  void preorderEnumerate(Node* cur);
  void levelorderEnumerate(Node* cur);


  /*searching*/
  bool searchBST(const int& val, Node* cur);

  ~BST(){
    Node* cur = m_root;
    freeTree(cur);
  }

 private:
  Node* m_root;
  bool deleteLeaf(int val, Node* parent, Node* cur);
  bool deleteSingleChildNode(int val, Node* parent, Node* cur);

};

#endif
