#include "Screen.h"
Screen::Screen(Base_class* parent, string name) : Base_class(parent, name) {} // ��������� � ������������ ������ Base_class
//����� �������
void Screen::signal(string& message) {
}

//����� �����������
void Screen::handler(string message) {
	cout<<message << endl;
}