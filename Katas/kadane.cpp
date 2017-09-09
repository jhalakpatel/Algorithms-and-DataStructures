// maximum sum array using kadane algorithm

#include "header.hpp"
using namespace std;

#define N 10
#define M 50

int maxsumSubArray(vector<int> &A) {

	int maxtillnow = 0;
	int maxofall = 0;

	for (int i=0; i<A.size(); ++i) {
		if (maxtillnow<0) maxtillnow=0;
		maxtillnow = max(maxtillnow + A[i], A[i]);
		maxofall = max(maxtillnow, maxofall);
	}

	return maxofall;
}

int main() {
	
	default_random_engine seed((random_device())());
	vector<int> A;
	for (int i=0; i<N; ++i) {
		A.emplace_back(uniform_int_distribution<int>(-M,M)(seed));
	}	

	cout <<"Array : ";
	for (int i=0; i<N; ++i) {
		cout <<A[i] <<", ";
	}
	cout << endl;

	cout <<"Maximum Sum Subrarry : "<<maxsumSubArray(A);

	return 0;
}
