#include <iostream>
using namespace std;


class BBsort{
  public:
    void bsort1(int A[], int l){
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

    void display1(int A[],int l){
      cout << "sorted array: "<< endl;
      for (int k=0;k<l;k++){
        cout << A[k] << "\t";
      }
    }
   

};

int main(){
  int L,b;
  int A[10000];
  cout << "enter length: ";
  cin >> L;
  for (int i = 0;i<L;i++){
    cin >> b;
    A[i] = b;
  }
  BBsort list;
  list.bsort(A,L);
  list.display(A,L);

 
  
return 0;}































































//Original Author: Dripto Biswas
