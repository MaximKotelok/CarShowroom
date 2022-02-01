#pragma once
#include <string>
#include <iostream>

using namespace std;

class car {
	string title;
	int year_of_manufacture;
	int engine_capacity;
	double price;

public:
	car();

	car(string title, int year_of_manufacture, int engine_capacity, double price);

	string get_title() const;

	int get_year_of_manufacture() const;

	int get_engine_capacity() const;

	double get_price() const;

	static car create_new_car();

	void print() const;
};
