#include <iostream>
#include <fstream>
using namespace std;

int main() {

	// read the input file into a array
	int i=0;
	int array_size = 100;
	int *unsorted_array = new int[array_size];
	ifstream fin("../input.txt");
	while(!fin.eof()) {
		fin >> unsorted_array[i];
		i++;
	}
}
