#ifndef SCREEN_H
#define SCREEN_H
#include "Base_class.h"
//����� ��� ����� �������� ������
class Screen : public Base_class {
public:
	//����� �������
	void signal(string& message);
	//����������
	void handler(string message);
	//�����������
	Screen(Base_class* parent, string name);

	void input_data();
};

#endif