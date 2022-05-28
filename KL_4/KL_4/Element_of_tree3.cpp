#include "Element_of_tree3.h"
#include "Application.h"

Element_of_tree3::Element_of_tree3(Base_class* parent, string name) : Base_class(parent, name) { this->class_number = 3; } // Обращение к конструктору класса Base_class

//Метод сигнала

void Element_of_tree3::signal(string& message) {
	if (message.find("Identification") != string::npos) {
		message = message.substr(15);
	}
	else if (message.find("PIN-code") != string::npos) {
		message = message.substr(9);
	}
	else if (message.find("Deposit money") != string::npos) {
		message = message.substr(14);
	}


}
//Метод обработчика
void Element_of_tree3::handler(string message) {
	string command;
	Application* root = (Application*)get_head_obj();
	getline(cin, command);
	while (command != "Turn off the ATM") {
		if (command.find("Identification") != string::npos || command.find("PIN-code") != string::npos) {
			root->emit_signal(this->getSignal(), command, HANDLER(Element_of_tree4::handler));
		}
	
		else if ((command.find("Deposit money") != string::npos || command == "Deposit money to the card") && root->is_auth && root->have_login) {
			root->emit_signal(this->getSignal(), command, HANDLER(Element_of_tree5::handler));
		}
		else if (command.find("Withdraw money") != string::npos && root->is_auth && root->have_login) {
			string sum = command.substr(15);
			int money_get = stoi(sum);
			if (money_get % 100 != 0) {
				message = "The amount is not a multiple of 100";
				root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
			}
			else if (root->cards[root->current_user_id].balance < money_get) {
				message = "There is not enough money on the card";
				root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
			}
			else {
				root->emit_signal(this->getSignal(), sum, HANDLER(Element_of_tree6::handler));

			}
		}
		else if (command == "End the session") {
			root->is_auth = false;
			message = "Ready to work";
			root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
		}
		else if (command == "SWOWTREE") {
			root->print_child_objsConditions(0);
		}
		else if(root->have_login && !root->is_auth) {
			message = "Ready to work";
			root->emit_signal(this->getSignal(), message, HANDLER(Screen::handler));
		}
		getline(cin, command);

	}
	root->emit_signal(this->getSignal(), command, HANDLER(Screen::handler));
}

