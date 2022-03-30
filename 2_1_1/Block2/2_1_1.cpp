#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std; 
class Class1 {
public:       
	Class1() {	cout << "Constructor\n";}       
	~Class1() { cout << "Destructor"; } 
};
int main(){        
	Class1 cl1;      
	return(0);
}
