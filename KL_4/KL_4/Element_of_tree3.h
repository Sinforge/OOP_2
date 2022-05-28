#ifndef ELEMENT_OF_TREE3_H
#define ELEMENT_OF_TREE3_H
#include "Base_class.h"
#include "card_info.h"

class Element_of_tree3 : public Base_class {
public:
	//����� �������
	void signal(string& message);
	//����������
	void handler(string message);
	//�����������
	Element_of_tree3(Base_class* parent, string name);

	card_info find_card_info(string card_number);

};

#endif