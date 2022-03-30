#pragma once
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
		int perimeter() { 
			P = a + b + c;
			return P; 
		}     
		double square() { 
			S = sqrt((P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c)));  
			return S;
		} 
};