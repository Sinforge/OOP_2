// 4_1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Classes.h"
using namespace std;

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
