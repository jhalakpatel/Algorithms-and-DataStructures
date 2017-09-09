#include "header.hpp"

using namespace std;

#define N 10
#define M 100

void insertionsort(vector<int> *Aptr) {
	vector<int> &A = *Aptr;
	for (int i=0; i<N-1; ++i) {
		int j = i+1;
		while(A[j-1]>A[j] && j>0) {
			swap(A[j-1], A[j]);
			j--;
		}
	}
}

int main() {
	default_random_engine seed((random_device())());
	vector<int> A(N);		// as already assigned memory, simply use assignment operator
	for (int i=0; i<N; ++i) {
		A[i] = uniform_int_distribution<int>(-M,M)(seed);
	}

	cout <<"Before sort :"<<endl;
	for (int i=0; i<N; i++) {
		cout <<A[i]<<", ";
	}

	insertionsort(&A);
	cout << endl;
	cout <<"After sort :"<<endl;	
	for (int i=0; i<N; i++) {
		cout <<A[i]<<", ";
	}

	cout << endl;

}
