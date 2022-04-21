#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Triangle.h"
#include <vector>
using namespace std;

int main()
{
	int n;
	int a, b, c;
	vector<Triangle> triangles;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		triangles.push_back(Triangle(a, b, c));
	}
	int n1, n2;
	char op;
	while (cin >> n1) {
		cin >> op >> n2;
		if (op == '+') {
			triangles[n1 - 1] + triangles[n2 - 1];
		}
		if (op == '-') {
			triangles[n1 - 1] - triangles[n2 - 1];
		}
	}
	triangles[n1 - 1].getInfo();

}


