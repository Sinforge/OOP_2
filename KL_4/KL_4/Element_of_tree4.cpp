#include "Element_of_tree4.h"
#include "card_info.h"
#include "Application.h"
Element_of_tree4::Element_of_tree4(Base_class* parent, string name) : Base_class(parent, name) { this->class_number = 4; } // Обращение к конструктору класса Base_class

//Метод сигнала
void Element_of_tree4::signal(string& message) {
}

//Метод обработчика
void Element_of_tree4::handler(string message) {
	int id;
	string text;
	Application* root = (Application*)this->get_head_obj();
	if (message.length() == 19) {
		for (int i = 0; i < root->cards.size(); i++) {
			if (root->cards.at(i).card_number == message) {
				id = i;
				break;
			}
		}
		root->current_user_id = id;
		root->have_login = true;
		text = "Enter the PIN code";
		root->emit_signal(this->getSignal(), text, HANDLER(Screen::handler));
	}
	else {
		if (root->cards[root->current_user_id].password == message) {
			root->is_auth = true;
			text = "Select the command";
			root->emit_signal(this->getSignal(), text, HANDLER(Screen::handler));
		}
	}
}