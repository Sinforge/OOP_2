#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;
class Stack {    
private:     
	string name;    
	int size;      
	int * mas;       
	int count_elem = 0;       
public:      
	Stack(string n, int s) {          
		name = n;      
		size=  s;     
		mas = new int[s];      
	}         
	string get_name() {      
		return name;       
	}             
	int get_size() {       
		return size;       
	}
	int get_count_elem() {      
		return count_elem;      
	}            
	bool add(int num) {        
		if (count_elem < size) {     
			mas[count_elem] = num;      
			count_elem++;       
			return true;       
		}           
		else {         
			return false;  
		}         
	}     
	bool get_number(int &num) {    
		if (count_elem > 0) {  
			num = mas[count_elem - 1];    
			count_elem--;    
			return true;    
		}          
		else {      
			return false;
		}
	}
};
#endif
