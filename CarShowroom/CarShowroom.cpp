#include "CarShowroom.h"
void CarShowroom::add_car() {
	cars.push_back(car::create_new_car());
}

void CarShowroom::delete_by_title(string title) {
	cars.erase(remove_if(cars.begin(), cars.end(), [title](car c) {return c.get_title() == title; }), cars.end());
}

void CarShowroom::print_all() {
	cout << string(50, '=') << "\n";
	for (auto el : cars)
		el.print();
	cout << string(50, '=') << "\n";
}

void CarShowroom::sorting(function<bool(const car&, const car&)> callback) {
	sort(cars.begin(), cars.end(), callback);
}

car& CarShowroom::search(function<bool(const car&)> callback) {
	return *find_if(cars.begin(), cars.end(), callback);
}