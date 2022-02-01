#include <iostream>
#include <functional>
#include "CarShowroom.h"

using namespace std;
class menu_element {
	string title;
	function<void(CarShowroom&)> code;
public:

	menu_element(string title, function<void(CarShowroom&)> code);

	void print();

	void print_active();

	void start(CarShowroom& cs);
};