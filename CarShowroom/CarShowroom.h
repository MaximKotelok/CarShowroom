#pragma once
#include "Car.h"
#include <vector>
#include <functional>
#include <algorithm>
class CarShowroom
{
	vector<car> cars;

public:
	void add_car() {
		cars.push_back(car::create_new_car());
	}

	void delete_by_title(string title) {
		cars.erase(remove_if(cars.begin(), cars.end(), [title](car c) {return c.get_title() == title; }), cars.end());
	}

	void print_all() {
		for (auto el : cars)
			el.print();
	}

	void sorting(function<bool(car,car)> callback) {
		sort(cars.begin(), cars.end(), callback);
	}

	car& search(function<bool(car)> callback) {
		return *find_if(cars.begin(), cars.end(), callback);
	}
};

