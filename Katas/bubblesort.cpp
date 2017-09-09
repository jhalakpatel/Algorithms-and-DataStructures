#include "header.hpp"

using namespace std;

#define N 10
#define M 100

void bubblesort(vector<int> *Aptr) {
	vector<int> &A = *Aptr;
	int imax = N-1;
	while(imax) {
		int idx = 0;
		for (int i=0; i<=imax; i++) {
			if (A[i]>A[idx]) {
				idx = i;
			}
		}
		swap(A[idx], A[imax]);
		imax--;
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

	bubblesort(&A);
	cout << endl;
	cout <<"After sort :"<<endl;	
	for (int i=0; i<N; i++) {
		cout <<A[i]<<", ";
	}

	cout << endl;

}
