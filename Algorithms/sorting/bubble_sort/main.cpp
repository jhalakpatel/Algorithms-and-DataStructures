#include <iostream>
#include <fstream>
using namespace std;

// global variable
int *unsorted_array;

void swap(int i, int j) {
	unsorted_array[i] = unsorted_array[i] + unsorted_array[j];
	unsorted_array[j] = unsorted_array[i] - unsorted_array[j];
	unsorted_array[i] = unsorted_array[i] - unsorted_array[j];
}



int main() {

	// read the input file into a array
	int i=0;
	bool swapped = false;
	int array_size = 100;
	unsorted_array = new int[array_size];
	ifstream fin("../input.txt");
	while(!fin.eof()) {
		fin >> unsorted_array[i];
		i++;
	}

	
	for (int i=0; i<array_size; i++) {
		// inner loop can stop looking at already sorted "n-1" items
		for (int j=0; j<array_size-i; j++) {
			if (unsorted_array[j] > unsorted_array[j+1]) {
				swap(j,j+1);
				swapped = true;
			}
		}
		if (swapped == true) {
			swapped = false;
		} else {
			// if none of the elements was swapped, it is already swapped
			break;	
		}
	}

	for (int i=0; i<array_size; i++){
		cout << unsorted_array[i] << endl;
	}
}
