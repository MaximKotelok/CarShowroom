#pragma once
#include "Car.h"
#include <vector>
#include <functional>
#include <algorithm>
class CarShowroom
{
	vector<car> cars;

public:
	void add_car();

	void delete_by_title(string title);

	void print_all();

	void sorting(function<bool(const car&, const car&)> callback);

	car& search(function<bool(const car&)> callback);
};

