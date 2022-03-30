
#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Base_class {
	private:
		string obj_name;
		Base_class* ptr_head_obj;
		vector<Base_class*> child_objs;
	public:
		Base_class(Base_class *  ptr_head_obj = NULL, string obj_name = "Root_obj") { 
			this->ptr_head_obj = ptr_head_obj;
			this->obj_name = obj_name;
		}
		void set_obj_name(string name) {
			obj_name = name;
		}
		string get_obj_name() {
			return obj_name;
		}
		
		void change_head_obj(Base_class* bs_class) {
				this->ptr_head_obj = bs_class;
		}
		Base_class* get_head_obj() {
			return ptr_head_obj;
		}
		void print_child_obj() {
			cout << obj_name << " ";
			for (int i = 0; i < child_objs.size(); i++) {
				cout << child_objs[i]->get_obj_name() << " ";
			}
			cout << endl;
			if (child_objs[child_objs.size() - 1]->get_count_child() != 0) {
				child_objs[child_objs.size() - 1]->print_child_obj();
			}

		}
		void add_child_obj(Base_class* child_obj) {
			child_objs.push_back(child_obj);
		}
		int get_count_child() {
			return child_objs.size();
		}
};

#endif // !
