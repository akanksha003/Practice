/*
  list.h
 */
#ifndef LIST_H
#define LIST_H

#include <stdio.h>

struct Node{
  Node(int val){
    m_val = val; 
    next = NULL;
  }
  int m_val;
  Node* next;
};


/*maintains alphabetical order*/
class LinkedList{
 public:
  
  LinkedList(){
    m_head = NULL;
  }

  Node* getHead(){
    return m_head;
  }


  bool insertItem(int val);
  Node* insertItem2(int val);
  bool deleteItem(int val);
  void printItems();
  Node* reverseList();
  bool findItem(int val);

  ~LinkedList(){
    deleteAll();
  }

 private:
  void deleteAll();
  Node* m_head;
};

















#endif //LIST_H
