#ifndef APPLICATION_H
#define APPLICATION_H
#include "Element_of_tree2.h"
#include "Element_of_tree3.h"
#include "Element_of_tree4.h"
#include "Element_of_tree5.h"
#include "Element_of_tree6.h"

#include "Base_class.h"
#include <iostream>
#include <string>
using namespace std;
class Application : public Base_class {
private:
	int class_number; //номер класса
	Base_class* parent; // Ссылки на объект класса-родителя и объект дочернего класса
	string parent_name, child_name; //Наименование объектов класса-родителя и дочернего класса соответственно
	string url; //Путь до оюъекта
public:

	//Параметрический конструктор	
	Application(Base_class* parent = NULL, string name = "Root_obj");

	//Построить дерево объектов
	void built_tree_objs();


	//Установить состояние объектов дерева
	void set_tree_condition();


	//Функция для обработки команд SET и FIND
	void tree_commands();

	//Вывод дерева иерархии
	int exec();
};

#endif