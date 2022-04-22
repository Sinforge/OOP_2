#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
using namespace std;
class Element {
public:
	string data;
	string temp;
private:
	int translateTO10(string hex) {
		int num = 0;
		for (int i = hex.length() - 1; i > -1; i--) {
			int digit = 0;
			if ((int)hex[i] <= (int)'9' && (int)(hex[i]) >= (int)'0') {
				digit = (int)(hex[i]) - (int)'0';
			}
			else {
				digit = ((int)(hex[i]) - (int)'A') + 10;

			}
			num += digit * pow(16, hex.length() - 1 - i);

		}
		return num;

	}
	string translateTO16(int number) {
		string hex = "";
		int ost;
		while (number != 0) {
			ost = number % 16;
			if (ost >= 10) {
				hex += (char)((int)'A' + (ost - 10));
			}
			else {
				hex += (char)((int)'0' + ost);
			}
			number = number / 16;
		}
		reverse(hex.begin(), hex.end());
		if (hex.length() == 1) {
			hex.insert(hex.begin(), '0');
		}
		return hex;
	}
public:
	Element(string data, string temp) {
		this->data = data;
		this->temp = temp;
	
	}
	void operator & (Element& elem) {
		int th_temp = translateTO10(this->temp);
		int ot_temp = translateTO10(elem.temp);
		int th_data = translateTO10(this->data);
		int ot_data = translateTO10(elem.data);
		this->data = translateTO16(th_data & (ot_data | (255 - (th_temp & ot_temp))));
		
	}
	void operator | (Element& elem) {
		int th_temp = translateTO10(this->temp);
		int ot_temp = translateTO10(elem.temp);
		int th_data = translateTO10(this->data);
		int ot_data = translateTO10(elem.data);
		this->data = translateTO16(th_data |(ot_data &(th_temp & ot_temp)));
	}
};

#endif
