#include "Application.h"
#include "Base_class.h"
Application::Application(Base_class* parent, string name) : Base_class(parent, name) {} // ��������� � ������������ ������ Base_class
void Application::built_tree_objs() { // ������ ������������� ����� ��������
	cin >> parent_name;
	this->set_obj_name(parent_name);
	while (true) {
		//������ ���� �� �������
		cin >> url;
		if (url == "endtree") {
			break;
		}
		//������ ��� ������ ������ � ����� ������
		cin >> child_name >> class_number;

		//���� ���� ������� ������ �� "/" ������ ��� ���� �� ������� ������
		if (url == "/") {
			parent = this;
		}

		else {
			//�������� ��������� �� ������ �� ��������� ���� 
			parent = this->getObjByURL(url);

			//���� ������ �� ������, ������� ������, ������� �������� �� ������ ������, � ������
			if (parent == nullptr) {
				cout << "Object tree";
				this->print_child_objs(0);
				cout << "\nThe head object " << url << " is not found";
				exit(0);

			}
		}
		// �������� ������� ������������� ������
		switch (class_number) {
		case 2:
			parent->add_child_obj(new Element_of_tree2(parent, child_name));
			break;
		case 3:
			parent->add_child_obj(new Element_of_tree3(parent, child_name));
			break;
		case 4:
			parent->add_child_obj(new Element_of_tree4(parent, child_name));
			break;
		case 5:
			parent->add_child_obj(new Element_of_tree5(parent, child_name));
			break;
		case 6:
			parent->add_child_obj(new Element_of_tree6(parent, child_name));
			break;
		}


	}

}
//���������� ��������� �������� ������
void Application::set_tree_condition() {
	string name;
	int cond;
	Base_class* b;
	while (cin) {
		cin >> name;
		cin >> cond;
		this->getObjByName(name)->set_condition(cond);
	}
}

//������� ��� ��������� ������ SET � FIND
void Application::tree_commands() {
	Base_class* current_obj = this, * found_obj = nullptr; // ������� ������, ��������� ������
	string com, com_url; // �������(FIND ��� SET), ���� �� �������
	cin >> com;
	//���� �� ������ END
	while (com != "END") {
		cout << endl;
		cin >> com_url;
		if (com == "SET") {
			if (com_url.substr(0, 2) == "//") {
				found_obj = this->getObjByName(com_url.substr(2));
			}
			//������� ������ �� ��������� ����
			else {
				found_obj = current_obj->getObjByURL(com_url);
			}
			//���� ������ �� ������, ������� �������������� ���������
			if (found_obj == nullptr) {
				cout << "Object is not found: " << current_obj->get_obj_name() << " " << com_url;
			}

			//���� ������, �������� � �������� ��������� �������� �������
			else {
				current_obj = found_obj;
				cout << "Object is set: " << current_obj->get_obj_name();
			}

		}
		else {

			//������� ������� ������
			if (com_url == ".") {
				cout << com_url << "     Object name: " << current_obj->get_obj_name();
			}
			//������� ���������� ������
			else if (com_url == "/") {
				cout << com_url << "     Object name: " << this->get_obj_name();
			}
			else {
				//���� ���� ���������� � "//" ������ ���������� ����� �� ����� ������
				if (com_url.substr(0, 2) == "//") {
					found_obj = this->getObjByName(com_url.substr(2));

				}
				else {
					found_obj = current_obj->getObjByURL(com_url);
				}

				//���� ������ �� ������, ������� �������������� ���������
				if (found_obj == nullptr) {
					cout << com_url << "     Object is not found";
				}
				//���� ������, �������� � �������� ������
				else {
					cout << com_url << "     Object name: " << found_obj->get_obj_name();

				}
			}
		}
		cin >> com;
	}

}
int Application::exec() { // ������� ������������� ����� � �������
	cout << "Object tree";
	this->print_child_objs(0);
	this->tree_commands();
	return 0;
}