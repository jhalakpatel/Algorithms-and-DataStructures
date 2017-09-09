#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string X, string Y, int x_l, int y_l) {

	// create a tabular storage location
	vector<vector<int> > L(x_l+1, vector<int>(y_l+1));

	for(int i=0; i<=x_l; i++) {
		for(int j=0; j<=y_l; j++) {
			if (i == 0 || j == 0) {
				L[i][j] = 0;
			} else if (X[i-1] == Y[j-1]) {
				L[i][j] = L[i-1][j-1] + 1;
			} else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}

	return L[x_l][y_l];
}

int main(){
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	cout << " LCS : " << lcs(X, Y, X.length(), Y.length()) << endl;
	return 0;
}
