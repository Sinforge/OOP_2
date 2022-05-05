#include "Base_class.h"

Base_class::Base_class(Base_class* ptr_head_obj = NULL, string obj_name = "Base_object") { //��������������� �����������
	this->ptr_head_obj = ptr_head_obj;
	this->obj_name = obj_name;
}

void Base_class::set_obj_name(string name) { //���������� ��� ��������
	this->obj_name = name;
}

string Base_class::get_obj_name() { // �������� ��� �������
	return this->obj_name;
}

void Base_class::change_head_obj(Base_class* bs_class) { // �������� ��������� �� �������� ������
	this->ptr_head_obj = bs_class;
}


Base_class* Base_class::get_head_obj() { // �������� ��������� �� �������� ������
	return this->ptr_head_obj;
}


void Base_class::print_child_objs(int level) {// ������� �� ����� �������� ������
	cout << endl;
	for (int j = 0; j < level; j++) {
		cout << "    ";
	}
	cout << this->obj_name;
	if (this->get_count_child() != 0) {
		for (int i = 0; i < this->get_count_child(); i++) {
			child_objs[i]->print_child_objs(level + 1);
		}
	}

}


void Base_class::print_child_objsConditions(int level) { // ������� �� ����� �������� ������
	cout << "\n";
	for (int j = 0; j < level; j++) {
		cout << "    ";
	}
	cout << obj_name;

	if (this->get_condition() != 0) {
		cout << " is ready";
	}
	else {
		cout << " is not ready";
	}
	if (this->get_count_child() != 0) {
		for (int i = 0; i < this->get_count_child(); i++) {
			child_objs[i]->print_child_objsConditions(level + 1);
		}
	}

}


Base_class* Base_class::getObjByName(string name) {//����� ������� �� �����
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
		return nullptr;

	}
}


void Base_class::add_child_obj(Base_class* child_obj) { //�������� �������� ����� � ������
	child_objs.push_back(child_obj);
}


unsigned int Base_class::get_count_child() { // �������� ���-�� �������� �������
	return child_objs.size();
}


void Base_class::set_condition(int condition) {//���������� ���������
	Base_class* base = this->get_head_obj();
	if (condition != 0) {//���� ����� �������� ������, ��������� �������� �� �����������
		while (base != NULL) {
			if (base->get_condition() == 0) {
				this->condition = 0;
				return;
			}
			base = base->get_head_obj();
		}
		this->condition = condition;
	}
	else {//���� ����� ���������, ��������� ���� ������ � ��� �����������
		for (int i = 0; i < this->get_count_child(); i++) {
			this->child_objs[i]->set_condition(0);
		}
		this->set_condition(0);
	}
}


int Base_class::get_condition() { //��������� ��������� �������
	return condition;
}

Base_class* Base_class::getObjByURL(string url) { //��������� ��������� �� ������ �� ��������� ����
	Base_class* found_obj;//��������� ������
	string main_coord = "";//������� ������
	string coord_for_check = ""; //���� �� �������� ������� � ��������
	bool check_first_elem = true;


	// ��������� �� ������� ������ � ���� �� ����� ������� � ��������
	for (int i = 0; i < url.length(); i++) {
		if (url[i] == '/' && main_coord == "") {
			continue;
		}
		else if (url[i] != '/' && check_first_elem) {
			main_coord += url[i];

		}
		else if (url[i] == '/') {
			check_first_elem = false;
			coord_for_check += url[i];
		}
		else {
			coord_for_check += url[i];
		}
	}

	//���������� ����� ������� �� ����
	for (int i = 0; i < this->get_count_child(); i++) {

		//���� ����� �������� �������� �������� ������ � ���������� ������ 
		if (this->child_objs[i]->get_obj_name() == main_coord) {
			//���� ����� ������� ���������� ���������
			if (coord_for_check == "") {
				return this->child_objs[i];
			}
			//����� �� ��������
			else {
				found_obj = this->child_objs[i]->getObjByURL(coord_for_check);
				if (found_obj != nullptr) {
					return found_obj;
				}
			}

		}
	}
	return nullptr;

}