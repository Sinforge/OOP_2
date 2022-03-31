#ifndef MASSIVE_H
#define MASSIVE_H
#include <iomanip>
#include <iostream>
using namespace std;
class Massive {     
private:				
	int size;             
	int * massive;      
public:       
	Massive() {   
		cin >> size;      
		massive = new int[size];    
		for (int i =0; i < size;i++) {      
			massive[i] = i * i;               
		}              
	}             
	void print() {    
		for (int i = size - 1; i >= 0; i--) {    
			cout << setw(5) <<  massive[i];     
		}            
	}
};
#endif