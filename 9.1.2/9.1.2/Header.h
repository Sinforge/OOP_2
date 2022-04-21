#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
using namespace std;
class Element {
private:
	string data;
	string temp;
	int translate(string hex) {
		int num = 0;
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
		return num;

	}
public:
	Element(string data, string temp) {
		this->data = data;
		this->temp = temp;
	}
	void operator & (Element& elem) {
		int th_temp = translate(this->temp);
		int ot_temp = translate(elem.temp);
		
	}
};

#endif
