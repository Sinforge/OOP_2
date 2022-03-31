#ifndef CALCULATOR_H
#define CALCULATOR_H
using namespace std;
class Calc {      
int f_num, s_num;  
int result;        
public:    
    Calc(int num1, int num2) {        
        f_num = num1;      
        s_num = num2;        
    }     
    int plus() {     
        result = f_num + s_num;   
        return result;
    }    
    int minus() {        
        result = f_num - s_num;          
        return result;    
    }     
    int del() {       
        result = f_num % s_num;        
        return result;  
    }     
    int mult() {     
        result = f_num * s_num;        
        return result; 
    }
};
#endif