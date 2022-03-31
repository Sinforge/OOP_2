#ifndef OBJECT2_H
#define OBJECT2_H
class Object2 { 
private:     
	int ch1;       
	int ch2;    
public:          
	void set_parameters(int a, int b) {
		ch1 = a;    
		ch2 = b; 
	}  
	friend int main();
};
#endif