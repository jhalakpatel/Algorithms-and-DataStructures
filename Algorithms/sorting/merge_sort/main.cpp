#include <iostream>
#include <fstream>
using namespace std;

int *unsorted_array;
int *sorted_array;

// TODO
void in_place_mergesort(){


}


void merge(int low, int mid, int high) {
	int i = low;
	int j = mid + 1;

	// populate new array with sorted merged elements	
	for (int k=low; k<=high; k++) {

		// lower subarray element < higher subarray element
		// i elements remaining, but all j elements are consumed
		if (i <= mid && ( j > high || (unsorted_array[i] < unsorted_array[j]))) {
			sorted_array[k] = unsorted_array[i];
			i++;
		} else {
			// either all i elements are consumed
			// or j is less than i elements
			sorted_array[k] = unsorted_array[j];
			j++;
		}
	}

	// copy the elements to original array
	for (int k=low;k<=high;k++){
		unsorted_array[k] = sorted_array[k];
	}
}


// top down approach
void mergesort(int low, int high){

	if (low < high) {

		// find mid index
		int mid = (low + high) / 2;

		// recursively call merge sort on lower sub array
		mergesort(low, mid);

		// call on higher subarray
		mergesort(mid+1, high);

		// merge the sub arrays
		merge(low, mid, high);
	}

	// once merge is done return;
	return;
}


int main() {

	// read the input file into a array
	int i=0;
	int array_size = 100;
	unsorted_array = new int[array_size];
	sorted_array = new int[array_size];
	ifstream fin("../input.txt");
	while(!fin.eof()) {
		fin >> unsorted_array[i];
		i++;
	}

	mergesort(0,array_size-1);

	for(int i=0; i<array_size;i++){
		cout << unsorted_array[i] << endl;
	}


}
