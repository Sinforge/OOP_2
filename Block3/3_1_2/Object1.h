#ifndef OBJECT1_H
#define OBJECT1_H
class Object1 {    
private:      
	int ch;  
public:     
	Object1(int num) {      
		ch = num;   
	}          
	friend int main();
};
#endif