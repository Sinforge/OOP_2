#include "Element_of_tree6.h"
#include "Application.h"
Element_of_tree6::Element_of_tree6(Base_class* parent, string name) : Base_class(parent, name) { this->class_number = 6; } // Обращение к конструктору класса Base_class

//Метод сигнала
void Element_of_tree6::signal(string& message) {
	if (message == "BAD") {
		message = "There is not enough money in the ATM";
	}
}

//Метод обработчика
void Element_of_tree6::handler(string message) { //message - сумма, которую необходимо выдать
	Application* root = (Application*)get_head_obj();
	int sum = stoi(message);
	int sum1 = sum;
	vector<int> bills = root->bills;
	int balance = root->cards[root->current_user_id].balance;
	int count_5000 = 0;
	int count_2000 = 0;
	int count_1000 = 0;
	int count_500 = 0;
	int count_100 = 0;
	for (int i = 0; i < bills[0]; i++) {
		if (sum < 5000) break;
		sum -= 5000;
		count_5000++;
	}
	for (int i = 0; i < bills[1]; i++) {
		if (sum < 2000) break;
		sum -= 2000;
		count_2000++;
	}
	for (int i = 0; i < bills[2]; i++) {
		if (sum < 1000) break;
		sum -= 1000;
		count_1000++;
	}
	for (int i = 0; i < bills[3]; i++) {
		if (sum < 500) break;
		sum -= 500;
		count_500++;
	}
	for (int i = 0; i < bills[4]; i++) {
		if (sum < 100) break;
		sum -= 100;
		count_100++;
	}
	if (sum == 0) {
		root->bills[0] -= count_5000;
		root->bills[1] -= count_2000;
		root-> bills[2] -= count_1000;
		root->bills[3] -= count_500;
		root->bills[4] -= count_100;
		root->cards[root->current_user_id].balance -= sum1;
		message = "Take the money: 5000 * " + to_string(count_5000) + " rub., 2000 * "
			+ to_string(count_2000) + " rub., 1000 * " + to_string(count_1000) + " rub., 500 * " + to_string(count_500)
			+ " rub., 100 * " + to_string(count_100) + " rub.";
	}
	else {
		message = "BAD";
	}
	root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));

}