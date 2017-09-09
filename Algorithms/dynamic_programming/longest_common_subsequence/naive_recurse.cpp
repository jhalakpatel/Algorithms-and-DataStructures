#include <iostream>
#include <string>

using namespace std;

int lcs(string X, string Y, int x_l, int y_l) {

	// if any of the string is 0, return 0
	if (x_l == 0 || y_l == 0) return 0;

	// if the character matches
	if (X[x_l] == Y[y_l]) {
		return 1 + lcs(X, Y, x_l-1, y_l-1);
	} else {
		return max(lcs(X, Y, x_l, y_l-1), lcs(X, Y, x_l-1, y_l));
	}
}

int main() {
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	cout << "Longest Common Subsequence : "<<lcs(X,Y,X.length(), Y.length()) << endl;
	return 0;
}
