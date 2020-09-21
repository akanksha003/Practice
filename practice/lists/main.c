/*
  main.c
 */

#include "list.h"
#include <stdio.h>
#include <iostream>
using namespace std;


Node* merge(Node* head1, Node* head2){

  Node* head = NULL;
  Node* tail = head;

  Node* p1 = head1;
  Node* p2 = head2;

  if(p1 == NULL)
    return p2;

  if(p2 == NULL)
    return p1;

  Node* q =new Node(-1);
  head = q;
  tail = q;
  
  
  while(p1 != NULL && p2 != NULL){
    
    if(p1->m_val <= p2->m_val){
      Node* q = new Node(p1->m_val);
      q->next = NULL;
      tail->next = q;
      tail = q;
      p1 = p1->next;
    }
    else{
      Node* q =new Node(p2->m_val);
      q->next =NULL;
      tail->next = q;
      tail = q;
      p2 = p2->next;
    }
  }
    if(p2 == NULL)
      tail->next = p1;

    else if(p1 == NULL)
      tail->next = p2;

    return head->next;

}

void printmergelist(Node* head){
  if(head == NULL)
    return;
  Node* p = head;
  while(p != NULL){
    printf("%d->", p->m_val);
    p = p->next;
  }
  printf("NULL\n");

}


int main(void){

  LinkedList myList;
  LinkedList myList2;

  myList.insertItem2(1);
  //  myList.insertItem2(3);
  Node* head1 = myList.insertItem2(5);

  myList2.insertItem2(2);
  myList2.insertItem2(4);
  Node* head2 = myList2.insertItem2(6);

  myList.printItems();
  myList2.printItems();


  Node* m = merge(head2, head1);
  printmergelist(m);

  return 0;
}

