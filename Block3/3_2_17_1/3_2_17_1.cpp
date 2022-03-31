#include <stdlib.h>
#include <stdio.h>
#include "Massive.h"
using namespace std;int main(){       
	Massive *  massive = new Massive();    
	massive->print(); 
	delete massive;    
	return(0);
}