#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
class Array {
public:
	int* mas;
	int size;

};
class ArrayInput : public Array {
public:
		ArrayInput(int size) {
			this->size = size;
			this->mas = new int[size];
			for (int i = 0; i < this->size; i++) {
				cin >> this->mas[i];
			}
		}
};
class ArraySortOutput : public Array {
public:
		void sort() {
			int temp;
			for (int i = 0; i < this->size- 1; i++) {
				for (int j = i; j < this->size; j++) {
					if (this->mas[j] < this->mas[i]) {
						temp = this->mas[i];
						this->mas[i] = this->mas[j];
						this->mas[j] = temp;
					}
				} 
			}
		}
		void print() {
			for (int i = 0; i < this->size; i++) {
				cout << this->mas[i] << " ";

			}
		}
};


class ArrayALL : public ArrayInput, public ArraySortOutput {
public:
	ArrayALL(int size) : ArrayInput(size) {}
	


};
#endif