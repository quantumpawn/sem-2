#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//_______________________class for bsort for array__________________//
class BBsort{
  public:
    void bsort(int A[], int l){
      for (int i = 0;i < l;i++){
        for (int j = 0;j<l-1;j++){
          if (A[j] > A[j+1]){
            int c = A[j];
            A[j] = A[j+1];
            A[j+1] = c;
          }  
        }
      }
    }

    void display(int A[],int l){
      cout << "sorted array: "<< endl;
      for (int k=0;k<l;k++){
        cout << A[k] << "\t";
      }
    }
   
};

//_______________________________________________________________//

//_______________class for bsort using linked list_______________//
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

class BBsort1{
public:
  void bsort1(node *h,int n){
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

  void display1(node *h){
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
//________________________________________________________________//

class Qsort{
public:

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] - Array to be sorted,
  low  - Starting index,
  high - Ending index */
void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void display(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << "\t";
}
 
};
 

int main(){ //example program
  
  //___________________________________________________________//
  clock_t T1;
  int L1,b1;
  int A[10000];
  cout << "enter length: ";
  cin >> L1;
  for (int i = 0;i<L1;i++){
    b1 = rand()%1000;
    A[i] = b1;
  }
  Qsort Arr;
  T1 = clock();
  Arr.qsort(A,0,L1-1);
  T1 = clock()-T1;
  cout << "time taken for array using Qsort: " << ((float)T1)/CLOCKS_PER_SEC << endl;
  //____________________________________________________________//
  clock_t t;
  SLL L;
  int n,b;
  cout << "enter length: ";
  cin >> n;
  for (int l=0;l<n;l++){
  b = rand()%1000;
  L.insert(b);}
  BBsort1 list;
  t = clock();
  list.bsort1(L.head,3);
  t = clock()-t;
  cout << "time taken for linked list using Bsort: " << ((float)t)/CLOCKS_PER_SEC << endl;
  //____________________________________________________________//
  clock_t T;
  int l,c;
  int A2[10000];
  cout << "enter length: ";
  cin >> l;
  for (int i = 0;i<l;i++){
    c = rand()%1000;
    A2[i] = c;
  }
  
  BBsort List;
  T = clock();
  List.bsort(A2,l);
  T = clock() - T;
  cout << "time taken for array using Bsort: " << ((float)T)/CLOCKS_PER_SEC << endl;
  //_____________________________________________________________//
  
return 0;}



















































//Original Author: Dripto Biswas
