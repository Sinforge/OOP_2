#include "Element_of_tree6.h"
Element_of_tree6::Element_of_tree6(Base_class* parent, string name) :
	Base_class(parent, name) {
	this->class_number = 6;
} // ��������� � ������������ ������ Base_class
//����� �������
void Element_of_tree6::signal(string& message) {
	cout << "\nSignal from " << this->Get_Abs_URL();
	message += " (class: 6)";
}
//����� �����������
void Element_of_tree6::handler(string message) {
	cout << "\nSignal to " << this->Get_Abs_URL() << " Text: " << message;

}