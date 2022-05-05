#include "Application.h"
#include "Base_class.h"
Application::Application(Base_class* parent, string name) : Base_class(parent, name) {} // Обращение к конструктору класса Base_class
void Application::built_tree_objs() { // Строит иерархическое древо объектов
	cin >> parent_name;
	this->set_obj_name(parent_name);
	while (true) {
		//Вводит путь до объекта
		cin >> url;
		if (url == "endtree") {
			break;
		}
		//Вводим имя нового класса и номер класса
		cin >> child_name >> class_number;

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
				cout << "\nThe head object " << url << " is not found";
				exit(0);

			}
		}
		// Создание объекта определенного класса
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

//Функция для обработки команд SET и FIND
void Application::tree_commands() {
	Base_class* current_obj = this, * found_obj = nullptr; // текущий объект, найденный объект
	string com, com_url; // Команда(FIND или SET), путь до объекта
	cin >> com;
	//Пока не введен END
	while (com != "END") {
		cout << endl;
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
int Application::exec() { // Выводит иерархическое древо в консоль
	cout << "Object tree";
	this->print_child_objs(0);
	this->tree_commands();
	return 0;
}