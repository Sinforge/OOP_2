#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base_class {
private:
	string obj_name; //��� �������
	Base_class* ptr_head_obj; //��������� �� ��������	 ������
	int condition;
	vector <Base_class*> child_objs;// ������ ���������� �� �������� �������
public:
	Base_class(Base_class* ptr_head_obj = NULL, string obj_name = "Base_object") { //��������������� �����������
		this->ptr_head_obj = ptr_head_obj;
		this->obj_name = obj_name;
	}
	void set_obj_name(string name) { //���������� ��� ��������
		this->obj_name = name;
	}
	string get_obj_name() { // �������� ��� �������
		return this->obj_name;
	}

	void change_head_obj(Base_class* bs_class) { // �������� ��������� �� �������� ������
		this->ptr_head_obj = bs_class;
	}
	Base_class* get_head_obj() { // �������� ��������� �� �������� ������
		return this->ptr_head_obj;
	}
	void print_child_objs(int level) { // ������� �� ����� �������� ������
		for (int j = 0; j < level; j++) {
			cout << "    ";
		}
		cout << obj_name << endl;
		if (this->get_count_child() != 0) {
			for (int i = 0; i < this->get_count_child(); i++) {
				child_objs[i]->print_child_objs(level + 1);
			}
		}

	}
	void print_child_objsConditions(int level) { // ������� �� ����� �������� ������
		for (int j = 0; j < level; j++) {
			cout << "    ";
		}
		cout << obj_name;
		Base_class* b = this;
		bool ready = true;
		while (b != NULL) {
			if (b->get_condition() == 0) {
				ready = false;
				break;
			}
			b = b->get_head_obj();
		}
		if (ready) {
			cout << " is ready\n";
		}
		else {
			cout << " is not ready\n";
		}
		if (this->get_count_child() != 0) {
			for (int i = 0; i < this->get_count_child(); i++) {
				child_objs[i]->print_child_objsConditions(level + 1);
			}
		}

	}
	Base_class* getObjByName(string name) {
		if (this->obj_name == name) {
			return this;
		}
		else {
			for (int i = 0; i < this->get_count_child(); i++) {
				Base_class* base = child_objs[i]->getObjByName(name);
				if (base != NULL) {
					return base;
				}
			}
			return NULL;

		}
	}
	void add_child_obj(Base_class* child_obj) { //�������� �������� ����� � ������
		child_objs.push_back(child_obj);
	}
	unsigned int get_count_child() { // �������� ���-�� �������� �������
		return child_objs.size();
	}
	void set_condition(int condition) {
		this->condition = condition;
	}
	int get_condition() {
		return condition;
	}

};
#endif
