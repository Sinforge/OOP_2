#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){       
	int num;        
	cin >> num;       
	num = num % 2;      
	if (num == 0) {            
		cout << "even";        }      
	else {              
		cout << "uneven";     
	}       
	return(0);
}
