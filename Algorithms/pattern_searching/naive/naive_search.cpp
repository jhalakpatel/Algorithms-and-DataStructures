#include <iostream>
#include <vector>
#include <string>

using namespace std;

void search(string pat, string text) {

	int N = text.length();
	int M = pat.length();
	// iterate over the text
	for (int i=0; i<N-M; i++) {

		int j;

		// iterate over pattern
		for (j=0; j<M; ++j) {
			if (text[i+j] != pat[j]) break;
		}

		if (j==M) {
			cout << "pattern found at : "<<i<<endl;
		}
	}
}


int main() {
	string text = "AABAACAADAABAAABAA";
	string pat = "AABA";
	search(pat, text);
	return 0;
}
