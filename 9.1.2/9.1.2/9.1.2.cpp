// 9.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	string hex = "A4";
	for (int i = hex.length() - 1; i > -1; i--) {
		int digit = 0;
		if ((int)hex[i] <= (int)'9' && (int)(hex[i]) >= (int)'0') {
			digit = (int)(hex[i]) - (int)'0';
			cout << digit << endl;
		}
		else {
			digit = ((int)(hex[i]) - (int)'A') + 10;

		}
		num += digit * pow(16, hex.length() - 1 - i);

	}
	cout << num;
}
