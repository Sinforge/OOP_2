#include "Application.h"
#include "Base_class.h"
Application::Application(Base_class* parent, string name) : Base_class(parent, name) {} // ��������� � ������������ ������ Base_class
void Application::built_tree_objs() { // ������ ������������� ����� ��������
	this->set_obj_name("System");
	/*while (true) {
	//������ ���� �� �������
	cin >> url;
	if(url == "endtree") {
		break;
	}
	//������ ��� ������ ������ � ����� ������
	//cin >> child_name >> class_number;

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
			cout << "\nThe head object " << url <<" is not found";
			exit(0);

		}
	}*/

	//������� �������
	Element_of_tree2* command_h = new Element_of_tree2(this, "Commnand_handler");
	Element_of_tree3* control_panel = new Element_of_tree3(this, "Control_panel");
	Element_of_tree4* ident_card = new Element_of_tree4(this, "Ident_card");
	Element_of_tree5* money_in = new Element_of_tree5(this, "Money_in");
	Element_of_tree6* money_out = new Element_of_tree6(this, "Money_out");
	Screen* screen = new Screen(this, "Screen");

	//�������� ��������
	this->add_child_obj(command_h);
	this->add_child_obj(control_panel);
	this->add_child_obj(ident_card);
	this->add_child_obj(money_in);
	this->add_child_obj(money_out);
	this->add_child_obj(screen);
	this->SetReadyALL();

	string message = "hi";
	//��������� ������ ��������
	this->set_connect(this->getSignal(), command_h, command_h->getHandler());
	this->set_connect(this->getSignal(), control_panel, control_panel->getHandler());
	this->set_connect(command_h->getSignal(), screen, screen->getHandler());
	this->set_connect(control_panel->getSignal(), ident_card, ident_card->getHandler());
	this->set_connect(control_panel->getSignal(), money_in, money_in->getHandler());
	this->set_connect(control_panel->getSignal(), money_out, money_out->getHandler());
	this->set_connect(control_panel->getSignal(), screen, screen->getHandler());
	this->set_connect(ident_card->getSignal(), screen, screen->getHandler());
	this->set_connect(money_in->getSignal(), screen, screen->getHandler());
	this->set_connect(money_out->getSignal(), screen, screen->getHandler());






	//parent->add_child_obj(new Element_of_tree2(parent, "Screen"));

	//->set_connect(obj1->getSignal(), obj2, obj2->getHandler());








	// �������� ������� ������������� ������

	/*switch(class_number) {
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
	}*/


}




void Application::set_tree_connects() {
	string url1;//���� �� ������� �������
	string url2;//���� �� ������� �������
	Base_class* obj1, * obj2;//��������� �� ������ � �������� � ������ � ������������
	cin >> url1;

	while (url1 != "end_of_connections") {
		cin >> url2;
		if (url1 == "/") {
			obj1 = this;
		}
		else {
			obj1 = this->getObjByURL(url1);
		}

		if (url2 == "/") {
			obj2 = this;
		}
		else {
			obj2 = this->getObjByURL(url2);
		}

		obj1->set_connect(obj1->getSignal(), obj2, obj2->getHandler());
		cin >> url1;
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

//������������� ����� ����� ��������� � ������
/*void Application::tree_connect_commands() {
	Base_class* start_obj, * end_obj;//��������� ������ � ������� ������
	string end_url, message = ""; //���� �� �������� ������� � ���������
	char cond;//��������� ��� ���������
	string com, com_url; //������� ������������, ���� �� ���������� �������
	cin >> com;
	//���� �� ������ END
	while (com != "END") {
		cin >> com_url;
		//��������� �������
		if (com == "EMIT") {
			getline(cin, message);
			if (message[message.length() - 1] == ' ') {
				message = message.substr(0, message.length() - 2);
			}
			start_obj = this->getObjByURL(com_url);
			if (start_obj == NULL) {
				cout << "\nObject " << com_url << " not found";
			}
			else {
				start_obj->emit_signal(start_obj->getSignal(), message);
			}
		}
		//������������� �����
		else if (com == "SET_CONNECT") {
			cin >> end_url;
			start_obj = this->getObjByURL(com_url);
			end_obj = this->getObjByURL(end_url);
			if (start_obj == NULL) {
				cout << "\nObject " << com_url << " not found";
			}
			else if (end_obj == NULL) {
				cout << "\nHandler object " << end_url << " not found";
			}
			else {
				start_obj->set_connect(start_obj->getSignal(), end_obj, end_obj->getHandler());

			}
		}
		//������� �����
		else if (com == "DELETE_CONNECT") {
			cin >> end_url;
			start_obj = this->getObjByURL(com_url);
			end_obj = this->getObjByURL(end_url);
			if (start_obj == NULL) {
				cout << "\nObject " << com_url << " not found";
			}
			else if (end_obj == NULL) {
				cout << "\nHandler object " << end_url << " not found";
			}
			else {
				start_obj->delete_connect(start_obj->getSignal(), end_obj, end_obj->getHandler());
			}
		}

		//������������� ��������� �������
		else if (com == "SET_CONDITION") {

			cin >> cond;
			int number = (int)cond - '0';
			start_obj = this->getObjByURL(com_url);
			if (start_obj == NULL) {
				cout << "\nObject " << com_url << " not found";
			}
			else {
				start_obj->set_condition(number);
			}
		}
		cin >> com;

	}
}
*/
//������� ��� ��������� ������ SET � FIND
void Application::tree_commands() {
	Base_class* current_obj = this, * found_obj = nullptr; // ������� ������, ��������� ������
	string com, com_url; // �������(FIND ��� SET), ���� �� �������
	cin >> com;
	//���� �� ������ END
	while (com != "END") {
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

//����� �������
void Application::signal(string& message) {
}

//����������
void Application::handler(string message) {

}
int Application::exec() { // ������� ������������� ����� � �������
	//cout << "Object tree";
	//this->print_child_objs(0);
	string message;
	cout << "Ready to work\n";
	//
	emit_signal(SIGNAL(Application::signal), message, HANDLER(Element_of_tree2::handler));
	
	emit_signal(SIGNAL(Application::signal), message, HANDLER(Element_of_tree3::handler));

	//this->tree_connect_commands();
	return 0;
}