#pragma once
#include "Car.h"
#include <vector>
#include <functional>
#include <algorithm>
class CarShowroom
{
	vector<car> cars;
	fstream fs;
	string path;
public:
	CarShowroom(string path);

	void add_car();

	void delete_by_id(int id);

	void print_all();

	void sorting(function<bool(const car&, const car&)> callback);

	car& search(function<bool(const car&)> callback);

	void save();

};

