#include "header.hpp"
using namespace std;

#define N 50
#define M 20

void countingsort(vector<int> *Aptr) {
	vector<int> &A = *Aptr;
	vector<int> countArray(M,0);	// indexarray of size equal to range of elements in the array
	vector<int> aux(A.size());

	// store count of element in array 
	for (int i=0; i<A.size(); ++i) {
		countArray[A[i]]++;
	}
	
	// store absolute index position, based on number of prev elements so far
	for (int i=1; i<M; ++i) {
		countArray[i] = countArray[i]+countArray[i-1];
	}
	
	// update the array
	for (int i=A.size()-1; i>=0; --i) {
		aux[countArray[A[i]]] = A[i];
		countArray[A[i]]--;
	}
	
	
	// transfer content of one vector to another
	A = aux;
}

int main(){

	default_random_engine seed((random_device())());
	vector<int> A;
	for (int i=0; i<N; ++i) {
		// generate a random number
		int a = uniform_int_distribution<int>(0,M-1)(seed);
		A.emplace_back(a);
	}

	cout << "before sorting : "<<endl;
	for (int i=0; i<N; ++i) {
		cout << A[i] <<", ";
	}

	countingsort(&A);

	cout << endl << "after sorting : "<<endl;
	for (int i=0; i<N; ++i) {
		cout << A[i] <<", ";
	}

	return 0;
}
