#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

#include "Car.h"
#include "Exceptions.h"
class CarShowroom
{
	vector<car> cars;
	fstream fs;
	string path;
public:
	CarShowroom(string path);

	int get_size();

	int get_total_cost();

	void add_car();

	void delete_by_id(int id);

	void print_all();

	void sorting(function<bool(const car&, const car&)> callback);

	car& search(function<bool(const car&)> callback);

	void save();

};

