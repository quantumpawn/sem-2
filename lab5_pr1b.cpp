#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next; //pointer to next node

};

class SLL{
public:
  node *head; //initialising head and tail nodes
  node *tail;
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


};

class BBsort{
public:
  void bsort(node *h,int n){
    for (int i = 0; i<n; i++){
      node *curr = new node;
      node *post = new node;
      node *pre = new node;
      curr = h;
      post = curr->next;
      while (curr->next != NULL){
        post = curr->next;
        if (curr->data > post->data){
          int c = curr->data;
          curr->data = post->data;
          post->data = c;}
        curr = curr->next;
      }
    }
  }

  void display(node *h){
    node *temp = new node;
    temp = h;
    cout << "sorted list: " << "\t";
    while (temp->next != NULL){
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << temp->data << endl;
  }

};

int main(){ //example program
  SLL L;
  int n,b;
  cout << "enter length: ";
  cin >> n;
  for (int l=0;l<n;l++){
  cin >> b;
  L.insert(b);}

  BBsort list;
  list.bsort(L.head,3);
  list.display(L.head);
  return 0;
}

















































//Original Author: Dripto Biswas
//Original Author: Dripto Biswas
