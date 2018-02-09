#include <iostream>
using namespace std;

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

int main(){
  int L,b;
  int A[10000];
  cout << "enter length: ";
  cin >> L;
  for (int i = 0;i<L;i++){
    cin >> b;
    A[i] = b;
  }
  Qsort list;
  list.qsort(A,0,L-1);
  list.display(A,L);

 
  
return 0;}























































//Original Author: Dripto Biswas
