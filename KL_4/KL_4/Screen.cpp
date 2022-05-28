#include "Screen.h"
Screen::Screen(Base_class* parent, string name) : Base_class(parent, name) {} // Обращение к конструктору класса Base_class
//Метод сигнала
void Screen::signal(string& message) {
}

//Метод обработчика
void Screen::handler(string message) {
	cout<<message << endl;
}