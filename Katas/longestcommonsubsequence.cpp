#include "header.hpp"
using namespace std;

int lcs(string A, string B) {

	vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));

	// if any one of then is zero, then LCS = 0	
	for (int i=0; i<A.size(); ++i) dp[i][0] = 0;
	for (int j=0; j<B.size(); ++j) dp[0][j] = 0;


	for (int i=1; i<=A.size(); ++i) {
		for (int j=1; j<=B.size(); ++j) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;		// if the char are equal, include both
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);	// include one and exclude other
			}
		}
	}
	return dp[A.size()][B.size()];
}

int main() {
	
	string A="XMJYAUZ";
	string B="MZJAWXU";

	cout << "longest common subsequence : " << lcs(A, B) << endl;

}
