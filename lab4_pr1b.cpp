#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

class queue{
  private:
  node *head, *tail;
  public:
  queue(){
    head = NULL;
    tail = NULL;
  }
  void push(int val){         //arranges as oldest -> newest
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL){
      head = temp;
      tail = temp;
    }
    else{
      tail->next = temp;
      tail = temp;
    }
  }
  void pop(){            //pops from head
    cout << "\n" << head->data << "\n" ;
    node *cur = new node;
    cur = head;
    head = cur->next;
    delete cur;
  }

  void display(){
    node *cur = new node;
    cur = head;
    if (head!=NULL){
    while (cur!=NULL){
      cout << cur->data << "\t";
      cur = cur->next;
      }
    }

    else{
    cout << "No elements!" << endl;}
  }

};

int main(){
  int L=0,b=0;
  cout << "enter length:";
  cin >> L;
  queue Q;
  for (int i=0;i<L;i++){
    cin >> b;
    Q.push(b);
  }
  Q.display();
  Q.pop();
  Q.display();
  return 0;
}
