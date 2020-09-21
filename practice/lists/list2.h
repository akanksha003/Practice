#ifndef LIST2_H
#define LIST2_H

#include <iostream>
using namespace std;

struct Node{

  Node(int value){
    val = value;
    next = NULL;
    prev = NULL;
  }
  int val;
  Node* next;
  Node* prev;
};


class DoublyLinkedList{

 public:
  
  DoublyLinkedList(){
    head = NULL;
  }

  ~DoublyLinkedList(){
    deleteAll();
  }

  Node* insertItem(int val);
  Node* deleteItem(int val);
  void printItems();

 private:
  Node* head;
  bool deleteAll();

};

























#endif //LIST2_H
