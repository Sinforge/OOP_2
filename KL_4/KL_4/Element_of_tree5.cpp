#include "Element_of_tree5.h"
#include "Screen.h"
#include "Application.h"
Element_of_tree5::Element_of_tree5(Base_class* parent, string name) : Base_class(parent, name) { this->class_number = 5; } // Обращение к конструктору класса Base_class

//Метод сигнала
void Element_of_tree5::signal(string& message) {
	if (isdigit(message[0])) {
		message = "The amount: " + message;
	}
}

//Метод обработчика
void Element_of_tree5::handler(string message) {
	Application* root = (Application*)get_head_obj();
	if (isdigit(message[0])) {
		int money = stoi(message);
		if (money == 5000 || money == 2000 || money == 1000 || money == 500 || money == 100) {
			root->amount_deposit += money;
			message = to_string((root->amount_deposit));
			root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
		}
	}
	else {
		root->cards[root->current_user_id].balance += root->amount_deposit;
		root->amount_deposit = 0;
		message = "Card balance " + to_string(root->cards[root->current_user_id].balance);
		root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
	}
}

