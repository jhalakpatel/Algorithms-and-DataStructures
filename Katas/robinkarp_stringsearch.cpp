#include "header.hpp"

using namespace std;

#define primeNumber 101
#define characterCount 256

int stringHashFunc(string str, int m) {
	int hash = 0;
	for (int i=0; i<m; ++i) {
		hash = (characterCount*hash + str[i])%primeNumber;
	}
	return hash;
}


vector<int> robinKarpSearch(string text, string pattern) {
	vector<int> indices;

	int m = pattern.size();
	int n = text.size();
	
	int p = 1;
	for (int i=0; i<m-1; ++i) {
		p = (p * characterCount) % primeNumber;
	}
	
	int textHash = stringHashFunc(text, m);
	int patternHash = stringHashFunc(pattern, m);

	for (int i=0; i<=n-m; ++i) {

		if (textHash==patternHash) {
			bool match = true;
			for (int j=0; j<m; ++j) {
				if (text[i+j]!=pattern[j]) {
				   	match = false;
					break;
				}
			}

			if (match) {
				indices.emplace_back(i);
			}
		}

		// prepare hash for the next window of text
		if (i<n-m) {
			textHash = (characterCount * (textHash - text[i]*p) + text[i+m]) % primeNumber;
		}

		// if the textHash is negative, make it positive
		if (textHash<0) textHash += primeNumber;
	}

	return indices;
}

int main() {


	//string text = "GEEKS FOR GEEKS";
    //string pattern = "GEEK";

	string text = "AABAACAADAABAABA";
	string pattern = "AABA";

	vector<int> indices = robinKarpSearch(text, pattern);

	cout <<"Pattern : "<<pattern<< " found in text : "<<text<<" at :"<<endl;
	for (int i=0; i<indices.size(); ++i) {
		cout << indices[i] << ", ";
	}
	cout << endl;
	return 0;
}
