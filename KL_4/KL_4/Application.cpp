#include "Application.h"
#include "Base_class.h"
Application::Application(Base_class* parent, string name) : Base_class(parent, name) {} // Обращение к конструктору класса Base_class
void Application::built_tree_objs() { // Строит иерархическое древо объектов
	this->set_obj_name("System");
	/*while (true) {
	//Вводит путь до объекта
	cin >> url;
	if(url == "endtree") {
		break;
	}
	//Вводим имя нового класса и номер класса
	//cin >> child_name >> class_number;

	//Если путь состоит только из "/" значит это путь на главный объект
	if (url == "/") {
		parent = this;
	}

	else {
	//Получаем указатель на объект по заданному пути
		parent = this->getObjByURL(url);

	//Если объект не найден, выводим дерево, которое собранно на данный момент, и ошибку
		if (parent == nullptr) {
			cout << "Object tree";
			this->print_child_objs(0);
			cout << "\nThe head object " << url <<" is not found";
			exit(0);

		}
	}*/

	//Объекты системы
	Element_of_tree2* command_h = new Element_of_tree2(this, "Commnand_handler");
	Element_of_tree3* control_panel = new Element_of_tree3(this, "Control_panel");
	Element_of_tree4* ident_card = new Element_of_tree4(this, "Ident_card");
	Element_of_tree5* money_in = new Element_of_tree5(this, "Money_in");
	Element_of_tree6* money_out = new Element_of_tree6(this, "Money_out");
	Screen* screen = new Screen(this, "Screen");

	//Иерархия объектов
	this->add_child_obj(command_h);
	this->add_child_obj(control_panel);
	this->add_child_obj(ident_card);
	this->add_child_obj(money_in);
	this->add_child_obj(money_out);
	this->add_child_obj(screen);
	this->SetReadyALL();

	string message = "hi";
	//Установка связей объектов
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








	// Создание объекта определенного класса

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
	string url1;//Путь до первого объекта
	string url2;//Путь до второго объекта
	Base_class* obj1, * obj2;//Указатель на объект с сигналом и объект с обработчиком
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

//Установить состояние объектов дерева
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

//Устанавливает связи между объектами в дереве
/*void Application::tree_connect_commands() {
	Base_class* start_obj, * end_obj;//Начальный объект и целевой объект
	string end_url, message = ""; //Путь до целевого объекта и сообщение
	char cond;//Состояние для устанвоки
	string com, com_url; //Команда пользователя, Путь до начального объекта
	cin >> com;
	//Пока не введен END
	while (com != "END") {
		cin >> com_url;
		//Рассылает сигналы
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
		//Устанавливает связь
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
		//Удаляет связь
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

		//Устанавливает состояние объекта
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
//Функция для обработки команд SET и FIND
void Application::tree_commands() {
	Base_class* current_obj = this, * found_obj = nullptr; // текущий объект, найденный объект
	string com, com_url; // Команда(FIND или SET), путь до объекта
	cin >> com;
	//Пока не введен END
	while (com != "END") {
		cin >> com_url;
		if (com == "SET") {
			if (com_url.substr(0, 2) == "//") {
				found_obj = this->getObjByName(com_url.substr(2));
			}
			//Находим объект по заданному пути
			else {
				found_obj = current_obj->getObjByURL(com_url);
			}
			//Если объект не найден, выводим соответсвующее сообщение
			if (found_obj == nullptr) {
				cout << "Object is not found: " << current_obj->get_obj_name() << " " << com_url;
			}

			//Если найден, сообщаем о успешной установке текущего объекта
			else {
				current_obj = found_obj;
				cout << "Object is set: " << current_obj->get_obj_name();
			}

		}
		else {

			//Выводим текущий объект
			if (com_url == ".") {
				cout << com_url << "     Object name: " << current_obj->get_obj_name();
			}
			//Выводим корененной объект
			else if (com_url == "/") {
				cout << com_url << "     Object name: " << this->get_obj_name();
			}
			else {
				//Если путь начинается с "//" значит происходит поиск по всему дереву
				if (com_url.substr(0, 2) == "//") {
					found_obj = this->getObjByName(com_url.substr(2));

				}
				else {
					found_obj = current_obj->getObjByURL(com_url);
				}

				//Если объект не найден, выводим соответсвующее сообщение
				if (found_obj == nullptr) {
					cout << com_url << "     Object is not found";
				}
				//Если найден, сообщаем о успешном поиске
				else {
					cout << com_url << "     Object name: " << found_obj->get_obj_name();

				}
			}
		}
		cin >> com;
	}

}

//Метод сигнала
void Application::signal(string& message) {
}

//Обработчик
void Application::handler(string message) {

}
int Application::exec() { // Выводит иерархическое древо в консоль
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