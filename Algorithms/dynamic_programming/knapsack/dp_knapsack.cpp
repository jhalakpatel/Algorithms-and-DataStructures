#include <iostream>
#include <vector>
using namespace std;

int Knapsack(int W, vector<int> weights, vector<int> values, int n) {
	// intitialize 2D array of size (n+1) x (n+1)
	vector<vector<int> > K(n+1, vector<int>(n+1));

	for (int i=0; i<=n; i++) {
		for (int w=0; w<=n; w++) {
			if (i==0 || w==0) {
				K[i][w] = 0;
			} else if (weights[i] < W) {
				// if includes the value, take from max of 
				// value(i) + K(i-1,W-w) or K(i-1, W)
				K[i][w] = max(values[i] + K[i-1][w-1], K[i-1][w]);
			} else {
				// if we can not include the "i" i.e. value, use the previous value
				K[i][w] = K[i-1][w];
			}
		}
	}

	// final matrix value will have the sum of all the optimal values
	return K[n][n];
}

int main() {
	vector<int> weights = {10 , 20 , 30};
	vector<int> values = {60, 100, 120};
	int W = 50;
	int n = 3;
	cout << "Knapsack : " << Knapsack(W, weights, values, n) << endl;
	return 0;
}
