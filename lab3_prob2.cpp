#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next; //pointer to next node

};

class CLL{
  node *head; //initialising head and tail nodes
  node *tail;
public:
  CLL(){
    head = NULL;
    tail = NULL;
  }
  void insert(int val){
    node *temp = new node; //temp node to be inserted
    temp->data = val;
    temp->next = head; //since temp node must point to head node
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
      tail->next = temp; //head and tail connected to temp to complete circle
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
    while (temp->next != head){
      cout << temp->data << "->"; //printing in expected format
      temp = temp->next; 
    }
    cout << temp->data << endl;}
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
    prev->next = head; //discard existing tail node
    delete tail;
    tail = prev; //set new tail node
  }

  void delAt(int pos){
    node *prev = new node;
    node *curr = new node;
    curr = head;
    if (pos == 1){
      tail->next = curr->next;
      head = tail->next;
    }
    else{
      while (pos > 2){
      pos =-1;
      curr = curr->next;
      prev = prev->next;
      if (curr == head){
      cout << "Not possible";}
      }
    }
    prev->next = curr->next;
    delete curr;
  }
  void countItems(){
    node *temp = new node;
    temp = head;
    if (head!=NULL){
    int c = 0;
    while (temp->next!= head){ //only 1 element case taken care of

    c += 1;
    temp = temp->next;}
    c = c + 1;
    cout << "Number of elements is " << c << endl;}

    else{

    cout << "there are no elements";}
  }
};

int main(){ //example program
  CLL L;
  L.insert(1);
  L.insert(2);
  L.display();
  L.insertAt(2,3);
  L.insert(4);
  L.display();
  L.delAt(1);
  L.display();
  L.countItems();
  return 0;
}






















































//Original Author: Dripto Biswas
