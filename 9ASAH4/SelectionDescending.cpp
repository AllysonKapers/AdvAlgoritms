//Seth Allen
//Paxton Proctor
//Ally Moore
//Assemble 1 File DescendingOrder.txt with how ever
//elements you want to process and click run
#include <iostream>
#include <fstream>
#include <iomanip>   //fix, setw
#include <stdlib.h> //srand, rand
#include <chrono>
#include <time.h>    //clock, clock_t
#include <vector>
#include <cmath>

using namespace std;

/* https://www.geeksforgeeks.org/selection-sort/ */
/* functions for selection sort*/
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

int main() {
	ifstream infile("DescendingOrder.txt");
	int temp;
	int nx = 0;

	while (infile >> temp) {
		//cout << temp<<" "<<endl;
		nx++;
	}
	cout << "Total:" << nx << endl;

	infile.close();
	infile.open("DescendingOrder.txt");

	int *A = new int[nx]();

	for (size_t i = 0; i<nx && infile >> A[i]; i++)
	infile.close();

	for (size_t i = 0; i < nx - 1; i++) {
		for (size_t j = i; j < nx; j++) {
			if (A[i] > A[j]) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	using Clock = chrono::high_resolution_clock;

	clock_t start, stop;

	long long Selectionelapsedtime;
	long long Insertionelapsedtime;

	start = Clock::now().time_since_epoch().count();

	selectionSort(A, nx);

	stop = Clock::now().time_since_epoch().count();
	Selectionelapsedtime = (long long)(stop - start);

	cout << "Selectiontime in nanoseconds: " << Selectionelapsedtime << '\n';
	delete[] A;

	system("pause");
	return 0;
}