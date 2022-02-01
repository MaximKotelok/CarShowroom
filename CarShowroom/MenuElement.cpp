#include "MenuElement.h"
menu_element::menu_element(string title, function<void(CarShowroom&)> code) {
	this->title = title;
	this->code = code;
}

void menu_element::print() {
	cout << title << "\n";
}

void menu_element::print_active() {
	cout << "->" << title << "<-\n";
}

void menu_element::start(CarShowroom& cs) {
	try {
		code(cs);
	}
	catch (FileNotOpenException exp) {
		cout << exp.what() << " | path: " << exp.get_path() << "\n";
	}	
	catch (NotFoundException exp) {
		cout << exp.what() << " | id: " << exp.get_id() << "\n";
	}
	catch (exception exp) {
		cout << exp.what() << "\n";
	}
}