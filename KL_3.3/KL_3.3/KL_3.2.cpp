// KL_3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <stdio.h>
#include "Application.h"
int main()
{
	Application* app = new Application(); //Создаем объкт класса Application
	app->built_tree_objs();//Строим иерархическое древо
	return app->exec(); // Выводим иерархическое древо на экран
}
