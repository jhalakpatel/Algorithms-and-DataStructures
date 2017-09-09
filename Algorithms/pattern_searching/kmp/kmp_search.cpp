#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ComputeLPS(string pat, int M, vector<int>& lps) {

	int len = 0;
	int i = 1;
	
	lps[0] = 0;

	while (i<M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len-1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string text) {
	int N = text.length();
	int M = pat.length();

	// initialize lps array	
	vector<int> lps (M);

	// compute lps : longest proper prefix which is also a suffix
	ComputeLPS(pat, M, lps);	

	int i = 0;
	int j = 0;

	while (i<N) {
		if (pat[j] == text[i]) {
			j++;
			i++;
		}

		if (j==M) {
			cout << "Found pattern at index " << i-j << endl;
		} else if (i<N && pat[j] != text[i]) {
			if (j!=0) {
				j = lps[j-1];
			} else {
				i = i+1; 
			}
		}
	}
}

int main() {
	string text = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(pat, text);
	return 0;
}
