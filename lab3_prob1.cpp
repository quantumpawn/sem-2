#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next; //pointer to next node
  node *prev; // pointer to previous node
};

class DLL{
  node *head; //initialising head and tail nodes
  node *tail;
public:
  DLL(){
    head = NULL;
    tail = NULL;
  }
  void insert(int val){
    node *temp = new node; //temp node to be inserted
    temp->data = val;
    temp->next = NULL; //since temp node must become new tail node
    if (head!= NULL){
      tail->next = temp;
      temp->prev = tail;
    }
    else{
      head = temp;
      temp->prev = NULL;
    }
    tail = temp;
  }

  void insertAt(int pos, int val){
    node *temp = new node;
    temp->data = val;
    node *pre = new node;
    node *curr = new node;
    pre = head;
    if (pos == 1){ //iserting new head node  
      temp->next = head;
      head = temp;
       
    }
    else{
    while (pos > 2){ //inserting node at pos != 1
      pos =- 1;
      pre = pre->next;
      if (pre == NULL){
      cout << "too few elements!";}

    }
    curr = pre->next;
    curr->prev = temp;
    pre->next = temp;
    temp->next = curr;
    temp->prev = pre;
    
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
    node *pre = new node;
    pre = tail->prev;
    pre->next = NULL;
    delete tail;
    tail = pre;
  }

  void delAt(int pos){
    node *pre = new node;
    node *curr = new node;
    node *nex = new node;
    pre = head;
    curr = pre->next;
    if (pos == 1){
      curr->prev = NULL;
      delete head;
      head = curr;
      
    }
    else{
      while (pos > 2){
      pos -= 1;
      curr = curr->next;
      pre = pre->next;
      if (curr == NULL){
      cout << "Not possible";}
      }
    if (curr->next != NULL){
    nex = curr->next;
    nex->prev = pre;
    pre->next = nex;}
    else{
    pre->next = NULL;}
    delete curr;}
  }
  void countItems(){
    node *temp = new node;
    temp = head;
    if (head!=NULL){
    int c = 0;
    while (temp->next!= NULL){

    c += 1;
    temp = temp->next;}
    c = c + 1;
    cout << "Number of elements is " << c << endl;}

    else{

    cout << "there are no elements";}
  }
};

int main(){ //example program
  DLL L;
  L.insert(1);
  L.insert(2);
  L.insert(4);
  L.insertAt(2,3);
  L.display();
  L.delAt(1);
  L.display();
  L.countItems();
  return 0;
}































































//Original Author: Dripto Biswas
