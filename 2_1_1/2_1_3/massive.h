#ifndef MASSIVE_H
#define MASSIVE_H
#include <iostream>
#include <iomanip>
using namespace std;
class Massive {  
	public:    
		int mas[10];   
		int n;    
		Massive() {     
			cin >> n;         
			cout << "N = " << n << endl;   
		}    
		void fill() {      
			for (int i = 0; i < n; i++) {     
				cin >> mas[i];
			}
		}        
		void print() {
			for (int j = 0; j < n; j++) { 
				cout << setw(5) << mas[j]; 
			}
		}   
		void reverse() { 
			int mas1[10];     
			for (int l = 0; l < n; l++) {
				mas1[l] = mas[n - l - 1];
			}            
			for (int k = 0; k < n; k++) { mas[k] = mas1[k]; } }
}; 
#endif
