#include "header.hpp"
using namespace std;

// algo is based on processing pattern, and works with O(n) , where n is length of the text
/*
 *	KMP Logic : some patterns which are already matched upto an extent, but not completly matched -- we do not need to rematch for  
 *	those pattern
 *
 *	all we need to do is : 
 *		1. preprocess pattern - calculate longest common prefix which is also a suffix
 *		2. when we match, its good, when unmatch, find out the lcs[j-1] --> such that we know the portion of pattern which 
 *			will match any way so no need to match them again 
 */


vector<int> calculateLongestProperPrefixSuffix(string pattern) {
	vector<int> lpsArray(pattern.size());
	int i = 1;
	int j = -1;
	int n = pattern.size();
	lpsArray[0] = -1;
	
	while(i<n) {
		while(j>=0 && pattern[i] != pattern[j+1]) j = lpsArray[j]; 
		if (pattern[i] == pattern[j+1]) j++;	// j == 0
		lpsArray[i] = j;
		i++;
	}
	return lpsArray;
}

vector<int> kmpSearch(string text, string pattern) {


	// caculate longest proper prefix which is also a suffix, such that we can use jnexttocompare = lps[j-1] -- skipping 
	// the pattern which is definatetly match
	vector<int> lps = calculateLongestProperPrefixSuffix(pattern);

	vector<int> indices;

	int m = pattern.size();

	for (int i=0; i<lps.size(); ++i) {
		cout << lps[i] <<", ";
	}

	
	int j = 0;
	for (int i=0; i<text.size(); ++i) {
		if (text[i] == pattern[j]) { 
			if (j==m-1) indices.emplace_back(i-m+1);
			j++;
			if (j==m) j = lps[j-1]+1;
		} else {
			// if jth index does not matches, modify to j to lps[j-1]
			if (j!=0) {
				j = lps[j-1]+1;
			}
		}	
	}


	return indices;

}

int main() {
	string A = "AABAACAADAABAABA";
	string B = "AABA";

	vector<int> indices = kmpSearch(A, B);

	cout << "String : "<<A<<" found in "<<B<<" at :"<<endl;
	for (int i=0; i<indices.size(); ++i) {
		cout << indices[i] <<", ";
	}

	cout << endl;
}
