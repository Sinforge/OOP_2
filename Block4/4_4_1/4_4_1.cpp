// 4_4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

class Base1 {
public:
	vector<int> massive;
	int size = 0;
	virtual void in_out() {
		int a;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cin >> a; 
			massive.push_back(a);

		}
	}

};

class Child1 : public Base1 {
public:
	virtual int func() {
		int first = massive[0];
		for (int i = 1; i < size; i++) {
			first -= massive[i];
		}
		return first;
	}

};
class Child2 : public Child1 {
public:
	int sum = 0;
public:
	int func() override{
		for (int i = 0; i < size; i++) {
			sum += massive[i];
		}
		return sum;
	}
};

class Child3 : public Child2 {
public:
	void in_out() override {
		cout << "Array dimension: " << this->size;
		cout << "\nThe original array:";
		for (int i = 0; i < size; i++) {
			cout << this->massive[i] << " ";
		
		}
		cout << "\nMin:" << Child1::func();
		cout << "\nSum:" << func();
	}
};
int main()
{
	Child3* bs;
	Child3 bs1 = Child3();
	bs = &bs1;
    bs->Base1::in_out();
    bs->in_out();
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
