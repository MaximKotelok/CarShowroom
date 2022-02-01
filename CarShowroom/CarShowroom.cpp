#include "CarShowroom.h"

CarShowroom::CarShowroom(string path) {
	this->path = path;
	fs.open(path, fstream::in);
	car tmp_car;
	while (fs >> tmp_car)
		cars.push_back(tmp_car);

	fs.close();

}

void CarShowroom::add_car() {
	int get_id = 0;
	if (cars.size() != 0)
		get_id = cars[cars.size() - 1].get_id()+1;
	cars.push_back(car::create_new_car(get_id));
}

void CarShowroom::delete_by_id(int id) {
	cars.erase(remove_if(cars.begin(), cars.end(), [id](car c) {return c.get_id() == id; }), cars.end());
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

void CarShowroom::save() {
	fs.open(path, fstream::out);
	for (auto el : cars)
		fs << el;
	fs.close();
}