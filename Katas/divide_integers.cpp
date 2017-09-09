#include "header.hpp"
using namespace std;

int divide(int dividend, int divisor) {
	long long n = dividend;
	long long m = divisor;

	int sign = (m<0) ^ (n<0) ? -1 : 1;

	long long q = 0;
	m = abs(m);
	n = abs(n);

	cout << "here"<<endl;

	int i;
	for (long long t=0,i=31; i>=0; --i) {
		// if legitimate index
		if ((t + (m<<i)) <= n) {
			// update the current sum
			t = t + (m<<i);
			// store the quotient index
			q |= (1LL << i);
		}
	}

	if (sign<0) {
		q = -q;
	}

	return (q>=numeric_limits<int>::max() || q<numeric_limits<int>::min()) ? numeric_limits<int>::max() : q;

}


int main() {

	int i1 = -1;
	int i2 = 1;
	cout << "Quotient :" << divide(i1, i2) << endl;
	return 0;
}
