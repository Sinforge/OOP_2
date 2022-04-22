// 9.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#include <vector>
using namespace std;

int main()
{
	int n, n1, n2;
	char op;
	vector<Element> elems;
	string data, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data >> temp;
		elems.push_back(Element(data, temp));
	}
	while (cin >> n1) {
		cin >> op >> n2;
		if (op == '&') {
			elems[n1 - 1] & elems[n2 - 1];
		}
		else {
			elems[n1 - 1] | elems[n2 - 1];
		}
	}
	cout << elems[n1 - 1].data;

}
