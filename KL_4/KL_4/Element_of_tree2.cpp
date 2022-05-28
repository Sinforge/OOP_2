#include "Element_of_tree2.h"
#include "Application.h"
#include "card_info.h"
Element_of_tree2::Element_of_tree2(Base_class* parent, string name) : Base_class(parent, name) { this->class_number = 2; } // Обращение к конструктору класса Base_class

//Метод сигнала
void Element_of_tree2::signal(string& message) {
	message = "Ready to work";
}
//Метод обработчика
void Element_of_tree2::handler(string message) {
	string card;
	Application* root = (Application*)this->get_head_obj();
	getline(cin, card);
	while (card != "End card loading") {
		card_info c_info;
		c_info.card_number = card.substr(0, 19);
		c_info.password = card.substr(20, 4);
		c_info.balance = stoi(card.substr(25));
		root->cards.push_back(c_info);
		getline(cin, card);
	}
	for (int i = 0; i < 5; i++) {
		cin >> root->bills[i];
	}

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, card);
	if (card == "End money loading") {
		root->emit_signal(SIGNAL(Element_of_tree2::signal), message, HANDLER(Screen::handler));
	}
	//Отправляем сигнал системе с данными и отправляем сигнал в объект экрана

}
