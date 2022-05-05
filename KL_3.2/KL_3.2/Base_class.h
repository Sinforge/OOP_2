#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base_class {
private:
	string obj_name; //��� �������
	Base_class* ptr_head_obj; //��������� �� �������� ������
	int condition;
	vector <Base_class*> child_objs;// ������ ���������� �� �������� �������
public:
	Base_class(Base_class* ptr_head_obj, string obj_name); //��������������� �����������



	void set_obj_name(string name); //���������� ��� ��������

	string get_obj_name(); // �������� ��� �������




	void change_head_obj(Base_class* bs_class); // �������� ��������� �� �������� ������



	Base_class* get_head_obj(); // �������� ��������� �� �������� ������



	void print_child_objs(int level);// ������� �� ����� �������� ������



	void print_child_objsConditions(int level); // ������� �� ����� �������� ������




	Base_class* getObjByName(string name);//����� ������� �� �����



	void add_child_obj(Base_class* child_obj); //�������� �������� ����� � ������



	unsigned int get_count_child(); // �������� ���-�� �������� �������



	void set_condition(int condition); //���������� ���������



	int get_condition(); //��������� ��������� �������

	Base_class* getObjByURL(string url); //��������� ��������� �� ������ �� ��������� ����


};
#endif


