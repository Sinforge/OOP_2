#ifndef APPLICATION_H
#define APPLICATION_H
#include "Element_of_tree2.h"
#include "Element_of_tree3.h"
#include "Element_of_tree4.h"
#include "Element_of_tree5.h"
#include "Element_of_tree6.h"
#include "Screen.h"
#include "card_info.h"

#include "Base_class.h"
#include <iostream>
#include <string>
using namespace std;
class Application : public Base_class {
private:
	int class_number = 1; //����� ������
	Base_class* parent; // ������ �� ������ ������-�������� � ������ ��������� ������
	string parent_name, child_name; //������������ �������� ������-�������� � ��������� ������ ��������������
	string url; //���� �� �������

public:
	vector<card_info> cards;
	vector<int> bills = vector<int>(5);
	int amount_deposit = 0;
	int current_user_id;
	bool is_auth = false;
	bool have_login = false;

	//��������������� �����������	
	Application(Base_class* parent = NULL, string name = "Root_obj");

	//��������� ������ ��������
	void built_tree_objs();

	//����� �������
	void signal(string& message);

	//����������
	void handler(string message);

	//��������� ������ ����� ���������
	void set_tree_connects();

	//��������� ������ ������������(SET_CONNECT, DELETE_CONNECT, EMIT, SET_CONDITION)
	void tree_connect_commands();

	//���������� ��������� �������� ������
	void set_tree_condition();


	//������� ��� ��������� ������ SET � FIND
	void tree_commands();



	//����� ������ ��������
	int exec();
};

#endif