#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){      
	string Name;   
	int Size;     
	int elem;      
	cin >> Name;     
	cin >> Size;       
	Stack stack1(Name, Size);   
	cin >> Name;      
	cin >> Size;      
	Stack stack2(Name, Size);  
	while(true) {            
		cin >> elem;         
		if (!stack1.add(elem)) {  
			break;            
		}             
		if (!stack2.add(elem)) {    
			break;             
		}
	}
	int m = max(stack1.get_count_elem(), stack2.get_count_elem());     
	cout << stack1.get_name() << " " << stack1.get_size() << endl; 
	cout << stack2.get_name() << " " << stack2.get_size() << endl;    
	cout << setiosflags(ios::left) << setw(15) << stack1.get_name() << setw(15) << stack2.get_name() << endl;   
	for (int i =0; i < m;i++) {                
		if (stack1.get_number(elem)) {        
			cout << setiosflags(ios::right) << setw(15) << elem;   
		}             
		else {        
			cout << setw(15) << "";    
		}          
		if (stack2.get_number(elem)) {     
			cout << setw(15) << elem;      
		}
		if (i < m - 1) { cout << endl; }
	}  
	return(0);
}