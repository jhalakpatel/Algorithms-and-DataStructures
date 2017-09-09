#include "header.hpp"
using namespace std;

#define N 10
#define M 100

vector<int> merge(vector<int> first, vector<int> second) {
	int i=0;
	int j=0;
	vector<int> result;
	while(i<first.size()&&j<second.size()) {
		if (first[i] <= second[j]) {
			result.emplace_back(first[i]);
			i++;
		} else if (first[i] > second[j]) {
			result.emplace_back(second[j]);
			j++;
		}
	}

	if (i==first.size()&&j==second.size()) return result;
	if (i==first.size()) {
		result.insert(result.end(), second.begin()+j, second.end());
	}
	if (j==second.size()) {
		result.insert(result.end(), first.begin()+i, first.end());
	}
	return result;
}

vector<int> mergesort(vector<int> A) {
	if (A.size()==1) return A;
	if (A.size()==0) return A;
	int mid = A.size()/2;
	vector<int> first(A.begin(),A.begin()+mid);
	vector<int> second(A.begin()+mid,A.end());
	first = mergesort(first);
	second = mergesort(second);
	return merge(first, second);

}

int main() {
	default_random_engine seed((random_device())());
	vector<int> A(N);
	for (int i=0; i<N; ++i) {
		A[i] = uniform_int_distribution<int>(0,100)(seed);
	}
	// sort the array for binary search
	//sort(A.begin(), A.end());
	
	cout << endl << "before sorting" << endl;
	
	for (int i=0; i<N; ++i) {
		cout << A[i] << ", ";
	}

	cout << endl << "after sorting" << endl;

	vector<int> result = mergesort(A);

	for (int i=0; i<N; ++i) {
		cout << result[i] << ", ";
	}
	cout << endl;
}

