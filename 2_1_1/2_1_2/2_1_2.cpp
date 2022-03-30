#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Triangle.h"
using namespace std;
int main(){       
	int a, b, c;
	cin >> a >> b >> c;       
	Triangle triangle(a, b, c);        
	cout << "P = " << triangle.perimeter() << "\n";     
	cout << "S = " << triangle.square();     
	return(0);
}
