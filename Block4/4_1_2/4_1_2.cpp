// 4_1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdlib.h>
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
    Class3(string n, int digit, int number = 3): Class2(n, digit, number) {}

};
class Class4 : public Class3 {
public:
    Class4(string name, int digit, int number = 4) : Class3(name, digit, number) {  }

};
int main()
{
    string ident;
    int number;
    cin >> ident >> number;
    Class1 class1 = Class1(ident, number);
    Class1 class2 = Class2(ident, number);
    Class1 class3 = Class3(ident, number);
    Class4 class4 = Class4(ident, number);
    class1.print_info(); cout << endl;
    class2.print_info(); cout << endl;
    class3.print_info(); cout << endl;
    class4.print_info();
}
