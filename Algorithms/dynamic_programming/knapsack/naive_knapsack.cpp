#include <iostream>
#include <vector>

using namespace std;

// find out maximum values that can be accomodated
int Knapsack(int W, vector<int> weights, vector<int> values, int n) {

	// if the W == 0 (complete consumption of W) 
	// or no items remaining, n = 0
	if (W==0 || n==0) return 0;
	
	// if including "n" the item is not possible, include n-1 item
	if (W < weights[n-1]) return Knapsack(W, weights, values, n-1);

	return max(values[n-1] + Knapsack(W-weights[n-1], weights, values, n-1), 
				Knapsack(W, weights, values, n-1));
}

int main() {

	vector<int> values = {60, 100, 120};
	vector<int> weights = {10, 20, 30};
	int W = 50;
	int n = 3;
	cout << "Knapsack : "<< Knapsack(W, weights, values, n) << endl;
	return 0;
};
