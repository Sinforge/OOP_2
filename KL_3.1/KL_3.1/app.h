#ifndef APP_H
#define APP_H
#include "Object.h"
#include "Base_class.h"
#include <iostream>
#include <string>
using namespace std;
class Application : public Base_class {
private:
	int class_number; //номер класса
	Base_class* parent; // Ссылки на объект класса-родителя и объект дочернего класса
	string parent_name, child_name; //Наименование объектов класса-родителя и дочернего класса соответственно
public:
	Application(Base_class* parent = NULL, string name = "Root_obj") : Base_class(parent, name) {} // Обращение к конструктору класса Base_class
	void built_tree_objs() { // Строит иерархическое древо объектов
		cin >> parent_name;
		this->set_obj_name(parent_name);
		while (true) {
			cin >> parent_name;
			if (parent_name == "endtree") {
				break;
			}
			cin >> child_name >> class_number;
			parent = this->getObjByName(parent_name);
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
	void set_tree_condition() {
		string name = "aaa";
		int cond;
		Base_class* b;
		while (name != "foaofa") {
			cin >> name;
			cin >> cond;
			b = this->getObjByName(name);
			b->set_condition(cond);
		}
	}
	int exec() { // Выводит иерархическое древо в консоль
		cout << "Object tree\n";
		this->print_child_objs(0);
		cout << "The tree of objects and their readiness\n";
		this->print_child_objsConditions(0);
		return 0;
	}
};

#endif
