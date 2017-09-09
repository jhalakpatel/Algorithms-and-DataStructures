#include "header.hpp"
using namespace std;

#define N 10
#define M 100

int partition(vector<int> *Aptr, int low, int high, int pivot) {
	vector<int> &A = *Aptr;

	// swap pivot with high
	swap(A[pivot], A[high]);

	int smallest = low;
	int index = low;
	while(index < high) {
		if (A[index] <= A[high]) {
			swap(A[smallest++], A[index++]);	// swap the current with smallest and incr
		} else {
			index++;	// just increment the index
		}
	}

	// finally swap the smallest (to put) with high
	swap(A[smallest], A[high]);
	return smallest;
}

void quicksort(vector<int> *Aptr, int low, int high) {
	if (low>high) return;
	vector<int> &A = *Aptr;
	default_random_engine seed((random_device())());
	int pivot = uniform_int_distribution<int>(low,high)(seed);
	cout << "pivot index " << pivot << endl;
	pivot = partition(&A, low, high, pivot);
	cout << "pivot index " << pivot << endl;
	quicksort(&A, low, pivot-1);
	quicksort(&A, pivot+1, high);
}

int main() {
	default_random_engine seed((random_device())());
	vector<int> A(N);
	for (int i=0; i<N; ++i) {
		A[i] = uniform_int_distribution<int>(0,100)(seed);
	}
	// sort the array for binary search
	//sort(A.begin(), A.end());
	quicksort(&A, 0, N-1);

	for (int i=0; i<N; ++i) {
		cout << A[i] << ", ";
	}
	cout << endl;
	cout << "done sorting" << endl;
}
