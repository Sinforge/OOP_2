#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	long long n;
	int count;
	count = 0;
	cin >> n;
	if (n == 0) {
		count = 1;
	}
	while (n != 0) {
		count = count + 1;
		n = n / 10;
	}
	cout << "Number of digits: " << count;
	return(0);
}
