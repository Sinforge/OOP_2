#include "Element_of_tree5.h"
Element_of_tree5::Element_of_tree5(Base_class* parent, string name) :
	Base_class(parent, name) {
	this->class_number = 5;
} // ��������� � ������������ ������ Base_class
//����� �������
void Element_of_tree5::signal(string& message) {
	cout << "\nSignal from " << this->Get_Abs_URL();
	message += " (class: 5)";
}
//����� �����������
void Element_of_tree5::handler(string message) {
	cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;
}