#include "header.hpp"

using namespace std;

string lcs(string A, string B) {

	vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
	string common;
	int mlen = 0;

	for (int i=1; i<=A.size(); ++i) {
		for (int j=1; j<=B.size(); ++j) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;	// simply update the length - to get continuous length
				if (dp[i][j] >= mlen) {
					mlen = dp[i][j];
					common = A.substr(i-mlen, mlen);
				}
			} else {
				dp[i][j] = 0;		// if mismtach, for includeing i and j both, dp[i][j] = 0;
			}

		}
	}

	return common;	

}

int main() {

	string A = "mynameisjhalakpatel";
	string B = "iamjhalakthecoder";

	cout << "max longest substring :"<<lcs(A, B);

	return 0;

}
