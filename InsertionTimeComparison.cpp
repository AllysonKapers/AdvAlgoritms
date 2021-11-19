#include <iostream>
#include <fstream>
#include <iomanip>   //fix, setw
#include <stdlib.h> //srand, rand
#include <chrono>
#include <time.h>    //clock, clock_t
#include <vector>
#include <cmath>

using namespace std;

/* https://www.geeksforgeeks.org/insertion-sort/ */
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
      
        key = arr[i];
        j = i - 1;
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
  ifstream infile("C.txt");
  int temp;
  int nx;

  while(infile >> temp) {
      //cout << temp<<" "<<endl;
      nx++;
  }
  cout<<"Total:"<<nx<<endl;

  infile.close();
  infile.open("C.txt");

  int *A = new int[nx]();

  for (size_t i=0; i<nx && infile >> A[i]; i++);
  infile.close();

  for (size_t i=0;i<nx-1;i++) {
    for (size_t j=i;j<nx;j++) {
      if (A[i]>A[j]) {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }
    }
  }

  using Clock = chrono::high_resolution_clock;

  clock_t start, stop;

  long long Selectionelapsedtime;
  long long Insertionelapsedtime;
  
  start = Clock::now().time_since_epoch().count();

  insertionSort(A, nx);

  stop = Clock::now().time_since_epoch().count();
  Insertionelapsedtime = (long long)(stop - start);

  cout << "Insertion Sorted array: \n";
  printArray(A, nx);

  cout << "Insertiontime in nanoseconds: " << Insertionelapsedtime << '\n';
  
  delete [] A;

  return 0;
} 
