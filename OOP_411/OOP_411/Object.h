#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include "Base_class.h"

class Element_of_tree : public Base_class {
		
public:
		Element_of_tree(Base_class* parent, string name) : Base_class(parent, name) {}
};
#endif

