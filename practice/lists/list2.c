
#include "list2.h"
#include <stdio.h>
#include <iostream>
using namespace std;


Node* DoublyLinkedList::insertItem(int val){

  if(head == NULL){
    Node* q = new Node(val);
    q->next = NULL;
    head = q;
    return head;
  }

  if(head->val > val){
    Node* q = new Node(val);
    q->next = head;
    head->prev = q;
    head = q;
    return head;
  }

  Node* p = head;
  while(p->next != NULL){
    if(p->val== val || p->next->val == val)
      return head;
    
    if(p->val < val && p->next->val > val){
      Node* q = new Node(val);
      q->next = p->next;
      q->prev = p;
      p->next->prev = q;
      p->next = q;
      return head;
    }

    p = p->next;
  }

  //after last element
  Node* q = new Node(val);
  q->next = p->next;
  q->prev = p;
  p->next = q;
  return head;

}


void DoublyLinkedList::printItems(){

  if(!head)
    printf("NULL\n");

  Node* p = head;
  while(p != NULL){
    printf("%d<->", p->val);
    p = p->next;
  }
  printf("NULL\n");

}


bool DoublyLinkedList::deleteAll(){

  if(!head)
    return false;

  Node* p = head;
  Node* n = head;

  while(p!= NULL){
    n = p->next;
    delete p;
    p = n;
  }
 
  head = NULL;
  return true;


}
