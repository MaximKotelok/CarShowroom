#include "CarShowroom.h"

CarShowroom::CarShowroom(string path) {
	this->path = path;
	fs.open(path, fstream::in);

	if (!fs.is_open())
		throw FileNotOpenException("File not open", path);
	car tmp_car;
	while (fs >> tmp_car)
		cars.push_back(tmp_car);

	fs.close();

}

int CarShowroom::get_size() {
	return cars.size();
}

int CarShowroom::get_total_cost() {
	return accumulate(cars.begin(), cars.end(), 0, [](int total, const car& c) {return total += c.get_price(); });
}

void CarShowroom::add_car() {
	int get_id = 0;
	if (cars.size() != 0)
		get_id = max_element(cars.begin(), cars.end(), [](const car& one, const car& two) {return one.get_id() < two.get_id(); })->get_id()+1;
	cars.push_back(car::create_new_car(get_id));
}

void CarShowroom::delete_by_id(int id) {
	if (find_if(cars.begin(), cars.end(), [id](const car& c) {return c.get_id() == id; }) == cars.end())
		throw NotFoundException("ID not found", id);
	
	cars.erase(remove_if(cars.begin(), cars.end(), [id](car c) {return c.get_id() == id; }), cars.end());
}

void CarShowroom::print_all() {
	cout <<"*" << string(98, '=') << "*\n";
	for (auto el : cars)
		cout << el;
	cout << "*" << string(98, '=') << "*\n";
}

void CarShowroom::sorting(function<bool(const car&, const car&)> callback) {
	sort(cars.begin(), cars.end(), callback);
}

car& CarShowroom::search(function<bool(const car&)> callback) {
	auto it = find_if(cars.begin(), cars.end(), callback);
	if (it == cars.end())
		throw exception("ID not found");
	return *it;
}

void CarShowroom::save() {
	fs.open(path, fstream::out);
	if (!fs.is_open())
		throw FileNotOpenException("File not open", path);
	for (auto el : cars)
		fs << el;
	fs.close();
}