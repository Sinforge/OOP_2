#ifndef SCREEN_H
#define SCREEN_H
#include "Base_class.h"
//Класс для ввода исходных данных
class Screen : public Base_class {
public:
	//Метод сигнала
	void signal(string& message);
	//Обработчик
	void handler(string message);
	//Конструктор
	Screen(Base_class* parent, string name);

	void input_data();
};

#endif