#include <iostream>
#include <stdlib.h>
#include "Object1.h"
#include "Object2.h"
using namespace std;
int main(){      
	int a,b,c ;      
	cin >> a;   
	Object1 obj1(a);      
	cin >> b >> c;   
	Object2 obj2;    
	obj2.set_parameters(b, c);   
	cout << "max = " << max(max(obj1.ch, obj2.ch1), obj2.ch2);     
	return(0);
}