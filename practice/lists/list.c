#include "list.h"
#include <stdio.h>
#include <iostream>
using namespace std;


Node* LinkedList::insertItem2(int val){
  if(m_head == NULL){
    Node* q = new Node(val);
    q->next = NULL;
    m_head = q;
    return m_head;
  }

  if(m_head->m_val > val){
    Node* q = new Node(val);
    q->next = m_head;
    m_head = q;
    return m_head;
  }

  Node* p = m_head;
  while(p->next != NULL){
    if(p->m_val == val || p->next->m_val == val)
      return m_head; //already exists!

    if(p->m_val < val && p->next->m_val > val){
      break;
    }
    p = p->next;
  }

  Node* q = new Node(val);
  q->next =p->next;
  p->next = q;
  return m_head;
}


bool LinkedList::insertItem(int val){

  
  Node* p = m_head;
  /*case 1: empty list*/
  if(m_head == NULL){
    p = new Node(val);
    p->next = NULL;
    m_head = p;
    return true;
  }

  /*case 2: somewhere in the middle*/
  while(p->next != NULL){

    if(p->m_val == val || p->next->m_val == val){
      return false;
    }

    else if(p->m_val > val){
      Node* q = new Node(val);
      q->next = p;
      m_head = q;
      return true;
    }
    
    else if(p->m_val < val && p->next->m_val > val){
      Node* q = new Node(val);
      q->next = p->next;
      p->next = q;
      return true;
    }
    p = p->next;
  
  }
  /*case 3: rear end*/
  //if we reach here, then p points at last element

  Node* q = new Node(val);

  if(p->m_val == val)
    return false;
  if(p->m_val > val){
    q->next = p;
    m_head = q;
    return true;
  }
  q->next = NULL;
  p->next = q;
  return true;
}

void LinkedList::printItems(){

  Node* p = m_head;
  while( p != NULL){
    printf("%d->", p->m_val); 
    p = p->next;
  }
  printf("NULL\n");

}

bool LinkedList::deleteItem(int val){

  if(m_head == NULL)
    return false; //no need to delete
  
  Node* p = m_head;
  if(m_head->m_val == val){
    Node* q = m_head->next;
    delete m_head;
    m_head = q;
  }
  while(p != NULL){
    if(p->next != NULL && p->next->m_val == val){
      Node* q = p->next;
      p->next = q->next;
      delete q;
      return true;
    }
    p = p->next;
  }

  return false;
  
}

void LinkedList::deleteAll(){
  Node* p = m_head;
  Node* n = m_head;
  while(p != NULL){
    n = p->next;
    delete p;
    p = n;
  }
}

Node* LinkedList::reverseList(){
  if(m_head == NULL)
    return m_head; //nothing to do!

  Node* prev = NULL;
  Node* cur = m_head;
  Node* next = cur;

  while(cur != NULL){
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  m_head = prev;
  return m_head;
}

bool LinkedList::findItem(int val){
  if(m_head == NULL)
    return false; //empty list!

  Node* p = m_head;
  
  while(p!=NULL){
    if(p->m_val == val)
      return true;
    p = p->next;
  }

  return false;


}


