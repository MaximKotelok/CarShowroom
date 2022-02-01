#pragma once
#include <iostream>

using namespace std;

class car {
	string title;
	int year_of_manufacture;
	int engine_capacity;
	double price;

public:
	car(string title, int year_of_manufacture, int engine_capacity, double price) {
		this->title = title;
		this->year_of_manufacture = year_of_manufacture;
		this->engine_capacity = engine_capacity;
		this->price = price;
	}

	
};
