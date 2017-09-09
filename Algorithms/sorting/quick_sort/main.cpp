#include <iostream>
#include <fstream>
using namespace std;

int array_size = 100;
int *unsorted_array;

void swap(int i, int j) {
	 int temp = unsorted_array[i];
	 unsorted_array[i] = unsorted_array[j];
	 unsorted_array[j] = temp;
} 


int partition_2(int low, int high) {

	int pivotValue = unsorted_array[high];

	int i = 0;
	int j = high-1;

	while (1) {
		// increment index i we find the value larger than pivot
		while (unsorted_array[i] < pivotValue) i++;

		// decrement index j till we find the value smaller than pivot
		while (unsorted_array[j] > pivotValue) j--;


		if (i>=j) {
			swap(i,high);
			return i;
		}

		// swap the value
		swap(i,j);
	}
}


int partition_1(int low, int high) {

	// choose pivot value
	int pivotValue = unsorted_array[high];

	// loop over the array
	int i = low - 1;

	// iterate over the array till the highest value
	for (int j=low; j <= high-1; j++){

		if (unsorted_array[j] < pivotValue) {
			// increament i
			i = i + 1;
			// wont swap if, i and j are incremented simul
			swap(i,j);
		}
	}
	swap(i+1,high);
	return i+1;
}

void quick_sort(int low, int high){

	// if low != high, when low == high, we have only one element, which is trivially sorted
	if (low < high) {
		// find pivot using parition algorithm 
		//int pivot = partition_1(low, high);
		int pivot = partition_2(low, high);

		// call quicksort on lower subarray
		quick_sort(low, pivot-1);

		// call quicksort on higher subarray
		quick_sort(pivot+1, high);
	}
}

int main() {

	// read the input file into a array
	int i=0;
	int array_size = 100;
	unsorted_array = new int[array_size];
	ifstream fin("../input.txt");
	while(!fin.eof()) {
		fin >> unsorted_array[i];
		i++;
	}

	quick_sort(0, array_size-1);

	for(int i=0; i<array_size; i++){
		cout << unsorted_array[i] << endl;
	}
}
