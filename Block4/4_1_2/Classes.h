#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <iostream>
using namespace std;
class Class1 {
private:
    string name;
    int digit;
public:
    Class1(string name, int digit, int number = 1) {
        this->name = name + '_' + ((char)('0' + number));
        this->digit = pow(digit, number);
    }
    void print_info() {
        cout << name << ' ' << digit;
    }


};

class Class2 : public Class1 {
public:
    Class2(string name, int digit, int number = 2) : Class1(name, digit, number) { }
};

class Class3 : public Class2 {
public:
    Class3(string n, int digit, int number = 3) : Class2(n, digit, number) {}

};
class Class4 : public Class3 {
public:
    Class4(string name, int digit, int number = 4) : Class3(name, digit, number) {  }

};
#endif