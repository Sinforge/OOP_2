#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base_class {
private:
	string obj_name; //Имя объекта
	Base_class* ptr_head_obj; //Указатель на головной объект
	int condition;
	vector <Base_class*> child_objs;// Массив указателей на дочерние объекты
public:
	Base_class(Base_class* ptr_head_obj, string obj_name); //Параметрический конструктор



	void set_obj_name(string name); //Установить имя объекета

	string get_obj_name(); // Получить имя объекта




	void change_head_obj(Base_class* bs_class); // Изменить указатель на головной объект



	Base_class* get_head_obj(); // Получить указатель на головной объект



	void print_child_objs(int level);// Вывести на экран дочерние классы



	void print_child_objsConditions(int level); // Вывести на экран дочерние классы




	Base_class* getObjByName(string name);//Поиск объекта по имени



	void add_child_obj(Base_class* child_obj); //Добавить дочерний класс в массив



	unsigned int get_count_child(); // Получить кол-во дочерних классов



	void set_condition(int condition); //Установить состояние



	int get_condition(); //Получение состояния объекта

	Base_class* getObjByURL(string url); //Получение указателя на объект по заданному пути


};
#endif


