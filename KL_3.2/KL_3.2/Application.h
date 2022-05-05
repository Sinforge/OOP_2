#ifndef APPLICATION_H
#define APPLICATION_H
#include "Element_of_tree2.h"
#include "Element_of_tree3.h"
#include "Element_of_tree4.h"
#include "Element_of_tree5.h"
#include "Element_of_tree6.h"

#include "Base_class.h"
#include <iostream>
#include <string>
using namespace std;
class Application : public Base_class {
private:
	int class_number; //����� ������
	Base_class* parent; // ������ �� ������ ������-�������� � ������ ��������� ������
	string parent_name, child_name; //������������ �������� ������-�������� � ��������� ������ ��������������
	string url; //���� �� �������
public:

	//��������������� �����������	
	Application(Base_class* parent = NULL, string name = "Root_obj");

	//��������� ������ ��������
	void built_tree_objs();


	//���������� ��������� �������� ������
	void set_tree_condition();


	//������� ��� ��������� ������ SET � FIND
	void tree_commands();

	//����� ������ ��������
	int exec();
};

#endif