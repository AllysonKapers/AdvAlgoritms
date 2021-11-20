//opens all 3 files
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

int main() {
	ifstream infile;
	int temp;
	int nx = 0;
	for (int i = 1; i <= 3; i++)
	{
		nx = 0;
		if (i == 1)
		{
			infile.open("SelectionAscending.txt");
			while (infile >> temp)
			{
				nx++;
			}
			cout << "Total:" << nx << endl;

			infile.close();
			infile.open("SelectionAscending.txt");
		}
		else if (i == 2)
		{
			infile.open("SelectionDescending.txt");
			while (infile >> temp)
			{
				nx++;
			}
			cout << "Total:" << nx << endl;

			infile.close();
			infile.open("SelectionDescending.txt");
		}
		else
		{
			infile.open("SelectionRandom.txt");
			while (infile >> temp)
			{
				nx++;
			}
			cout << "Total:" << nx << endl;
			infile.close();
			infile.open("SelectionRandom.txt");
		}
		int *A = new int[nx]();

		for (size_t i = 0; i<nx && infile >> A[i]; i++)
			infile.close();

		for (size_t i = 0; i < nx - 1; i++)
		{
			for (size_t j = i; j < nx; j++)
			{
				if (A[i] > A[j])
				{
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

		insertionSort(A, nx);

		stop = Clock::now().time_since_epoch().count();
		Insertionelapsedtime = (long long)(stop - start);

		cout << "Insertiontime in nanoseconds: " << Insertionelapsedtime << '\n';

		delete[] A;
	}
	system("pause");
	return 0;
}