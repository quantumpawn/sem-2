#include <iostream>
using namespace std;

//----------------Linked List class---------------------------------//
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


};

//--------------------------------------------------------------------//

void bsearch(int arr[], int L, int R, int key){
  int mid = (L+R)/2;  //finding middle index
  if (key<= arr[R] && key>=arr[L]){ //for sorted array, key must at least satisfy this condition
    if (arr[mid] == key){
      cout << "found at index: " << mid << endl;  
    }
    else{
      if (key < arr[mid]){//Confine search to left branch of binary tree.
        R = mid-1;
        bsearch(arr, L,R,key);
      }
      else{ //Confine search to right branch of binary tree.
        L = mid+1;
        bsearch(arr,L,R,key);
      }
    }
  }
  else{
  cout << "not found"<< endl;}
}

void bsearch2(node *p, int n,int key){
  int A[10000];
  for (int j=0;j<n;j++){
    A[j] = p->data;
    p = p->next;
  }
  bsearch(A,0,n,key);
}

int main(){
  int n,a,key;
  SLL list;
  cout << "enter no. of elements: ";
  cin >> n;  
  cout << "enter elements in sorted format: ";
  for (int i=0;i<n;i++){
    cin >> a;
    list.insert(a);
  }
  cout << "enter key: ";
  cin >> key;
  list.display();
  bsearch2(list.head,n,key);
  

return 0;}
