#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

class stack
{
  private:
  node *head, *tail;
  public:
  stack()
  {
    head = NULL;
    tail = NULL;
  }

  void push(int val)
  {
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL){
      head = temp;
      tail = temp;
      temp = NULL;

    }
    else{
      tail->next = temp;
      tail = temp;
    }
  }

  void display()                // displays as oldest -> newest
  {
    node *cur = new node;
    cur = head;
    while (cur!=NULL){
      cout << cur->data << "\t";
      cur = cur->next;
    }
  }
  
  void pop()
  {
    node *cur = new node;
    node *pre = new node;
    if (head!=NULL){           // for null stack
    cout << tail->data << "\n";//pops tail node
    cur = head;
    while (cur->next != NULL){
      pre = cur;
      cur =  cur->next;
    }
    tail = pre;
    tail->next = NULL;
    delete cur;}
    else{
    cout << "No Elements!" << endl;}
    

  }

};

int main()
{
  int b = 0,L=0;
  stack S;
  cout << "enter L: "; //# of entries.
  cin >> L;
  for (int i=0; i<L;i++){
  cin >> b;
  S.push(b);} //create stack
  S.display();
  cout << "\n";
  S.pop();
  S.display();
  return 0;

}
