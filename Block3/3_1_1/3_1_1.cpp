#include <iostream>
#include "calculator.h"
using namespace std;
int main() {     
	int f_num, s_num, count = 0;
	char ch;       
	int start = 0;   
	cin >> f_num;       
	while (true) { 
		cin >> ch;     
		if (ch == 'C') { 
			return 0; 
		}            
		cin >> s_num;     
		Calc calc1(f_num, s_num);   
		if (ch == '+') { f_num = calc1.plus(); } 
		else if (ch == '-') { f_num = calc1.minus(); }
		else if (ch == '%') { f_num = calc1.del(); }
		else if (ch == '*') { f_num = calc1.mult(); }     
		count++;              
		if (count == 3) {
			if (start == 0) { 
				cout << f_num;    
				start = 1;
			} 
			else { cout << endl << f_num; }     
			count = 0; } 
	}     
	return 0;
}

