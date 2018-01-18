#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next; //pointer to next node

};

class SLL{
  node *head; //initialising head and tail nodes
  node *tail;
public:
  SLL(){
    head = NULL;
    tail = NULL;
  }
  void insert(int val){
    node *temp = new node; //temp node to be inserted
    temp->data = val;
    temp->next = NULL; //since temp node must become new tail node
    if (head!= NULL){
      tail->next = temp;
    }
    else{
      head = temp;
    }
    tail = temp;
  }

  void insertAt(int pos, int val){
    node *temp = new node;
    temp->data = val;
    node *prev = new node;
    prev = head;
    if (pos == 1){ //iserting new head node  
      temp->next = head;
      head = temp;
       
    }
    else{
    while (pos > 2){ //inserting node at pos != 1
      pos =- 1;
      prev = prev->next;
      if (prev == NULL){
      cout << "too few elements!";}

    }
    temp->next = prev->next; //takes care of the case pos = 2
    prev->next = temp;
    
    }

  }

  void display(){
    node *temp = new node;
    temp = head;
    if (head != NULL){
    while (temp->next != NULL){
      cout << temp->data << "->"; //printing in expected format
      temp = temp->next; 
    }
    cout << temp->data;}
    else{
    cout << "empty list!";}
    cout << "\n";
  }

  void del(){
    node *prev = new node;
    prev = head;
    while (prev->next != tail){
      prev = prev->next;
    }
    prev->next = NULL; //discard existing tail node
    tail = prev; //set new tail node
  }

  void delAt(int pos){
    node *prev = new node;
    node *curr = new node;
    prev = head;
    curr = prev->next;
    if (pos == 1){
      prev->next = head->next;
      head = prev;
    }
    else{
      while (pos > 2){
      pos =-1;
      curr = curr->next;
      prev = prev->next;
      if (curr == NULL){
      cout << "Not possible";}
      }
    }
    prev->next = curr->next;
    delete curr;
  }
};

int main(){ //example program
  SLL L;
  L.insert(1);
  L.insert(2);
  L.insertAt(2,3);
  L.display();
  L.delAt(2);
  L.display();
  return 0;
}
