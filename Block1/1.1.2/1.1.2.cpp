#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){        
	int num, sum;       
	sum = 0;      
	cin >> num;     
	if (num <= 0) {          
		cout << "n is wrong (" << num << ")";   
	}       
	else {           
		for (int i = 1; i <= num; i++) {        
			sum = sum + i;               
		}             
		cout << "Sum_n = " << sum;    
	}        return(0);}
