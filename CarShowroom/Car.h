#pragma once
#include <iostream>

using namespace std;

class car {
	string title;
	int year_of_manufacture;
	int engine_capacity;
	double price;

public:
	car() {}

	car(string title, int year_of_manufacture, int engine_capacity, double price) {
		this->title = title;
		this->year_of_manufacture = year_of_manufacture;
		this->engine_capacity = engine_capacity;
		this->price = price;
	}

	void print() {
		cout << title << " | year of manufacture: " << year_of_manufacture << " | engine capacity: " << engine_capacity << " | price: " << price << "\n";

	}
};
