#include <iostream>
using namespace std;

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

int main(){ //Element-not-found example. Other cases are true.

  int arr[] = {1,2,3,5,6,7};
  int key = 4;
  int R = 6;
  bsearch(arr,0,R,key);
  return 0;
}

























































//Original Author: Dripto Biswas
