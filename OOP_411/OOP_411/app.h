#ifndef APP_H
#define APP_H
#include <iostream>
#include "Base_class.h"
#include "Object.h"
using namespace std;


class Application : public Base_class {
private:
	Base_class* parent, *child;
	string parent_name, child_name;
public:
	void build_tree() {
		cin >> parent_name;
		parent = this;
		parent->set_obj_name(parent_name);

		cin >> parent_name >> child_name;
		while (parent_name != child_name) {
			if (parent_name != parent->get_obj_name()) {
				parent = child;
			}
			child = new Element_of_tree(parent, child_name);
			parent->add_child_obj(child);
			cin >> parent_name >> child_name;
		}
	}
		
	int exec() {
		cout << this->get_obj_name() << endl;
		this->print_child_obj();
		return 0;
	}
	
};



#endif