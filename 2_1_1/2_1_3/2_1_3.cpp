#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "massive.h"
using namespace std;
	int main(){      
		Massive mas;  
		mas.fill();   
		mas.print();  
		cout << endl;   
		mas.reverse();   
		mas.print(); 
		return(0);
	}