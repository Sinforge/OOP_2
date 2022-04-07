#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iomanip>
using namespace std;
class Array {
public:
	int* mas;
	int size;

};
class ArrayInput : virtual public Array {
public:
		ArrayInput(int size) {
			this->size = size;
			this->mas = new int[size];
			for (int i = 0; i < this->size; i++) {
				cin >> this->mas[i];
			}
		}
};
class ArraySortOutput : virtual public Array {
public:
		void sort() {
			int temp;
			for (int i = 0; i < size- 1; i++) {
				for (int j = i; j < size; j++) {
					if (mas[j] < mas[i]) {
						temp = mas[i];
						mas[i] = mas[j];
						mas[j] = temp;
					}
				} 
			}
		}
		void print() {
			cout <<setw(5) << mas[0];
			for (int i = 1; i < size; i++) {
				cout << setw(5) << mas[i];

			}
		}
};


class ArrayALL : public ArrayInput, public ArraySortOutput {
public:
	ArrayALL(int size) : ArrayInput(size) {}
};
#endif