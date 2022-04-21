#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
private:
	int a, b, c;
	double S, P;
public:
	Triangle(int A, int B, int C) {
		a = A;
		b = B;
		c = C;

	}
	void operator +(Triangle& other) {
		int a1 = this->a + other.a;
		int b1 = this->b + other.b;
		int c1 = this->c + other.c;
		if ((a1 + b1 > c1) && (a1 + c1 > b1) && (b1 + c1 > a1)) {
			this->a = a1;
			this->b = b1;
			this->c = c1;
			return;
		}
		return;
	}
	void operator -(Triangle& other) {
		int a1 = this->a - other.a;
		int b1 = this->b - other.b;
		int c1 = this->c - other.c;
		if ((a1 + b1 > c1) && (a1 + c1 > b1) && (b1 + c1 > a1) && a1 > 0 && b1 > 0 && c1 > 0) {
			this->a = a1;
			this->b = b1;
			this->c = c1;
		}
	}
	int perimeter() {
		P = a + b + c;
		return P;
	}
	void getInfo() {
		cout << "a = " << this->a << "; b = " << this->b << "; c = " << this->c << ".";
	}
	double square() {
		S = sqrt((P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c)));
		return S;
	}
};
#endif // !TRIANGLE_H

