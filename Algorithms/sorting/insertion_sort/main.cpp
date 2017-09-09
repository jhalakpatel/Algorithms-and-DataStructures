#include <iostream>
#include <fstream>
using namespace std;

int *unsorted_array;
int array_size = 100;

void swap(int i, int j){
	unsorted_array[i] = unsorted_array[i] + unsorted_array[j];
	unsorted_array[j] = unsorted_array[i] - unsorted_array[j];
	unsorted_array[i] = unsorted_array[i] - unsorted_array[j];
}

// insertion sort basic
void insertion_1(){
	for(int i=1; i<array_size; i++) {
		// pick and element from unsorted list and place it in correct position in sorted list
		int j = i;

		// work on the sorted list
		while(j>0) {
			if (unsorted_array[j-1] > unsorted_array[j]) {
				swap(j-1,j);
			}
			j--;
		}
	}
}


// insertion sort with inplace swap
void insertion_2(){
	for(int i=1; i <array_size; i++){
		// store value to be inserted in temp variable
		int temp = unsorted_array[i];

		// initialize index for unsorted array
		int j = i - 1;

		// compare the value with the unsorted array until smaller value is found
		while ((j >= 0) && unsorted_array[j] > temp) {

			// shift the number if the its larger the value to be inserted
			unsorted_array[j+1] = unsorted_array[j];

			// move one index to the left
			j = j - 1;
		}

		// once the value is more than the unsorted array value index
		unsorted_array[j+1] = temp;
	}
}


int main() {

	// read the input file into a array
	int i=0;
	unsorted_array = new int[array_size];
	ifstream fin("../input.txt");
	while(!fin.eof()) {
		fin >> unsorted_array[i];
		i++;
	}

	insertion_2();


	for(int i=0; i<array_size; i++) {
		cout << unsorted_array[i] << endl;
	}
}
