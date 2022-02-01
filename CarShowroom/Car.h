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
	car() {}

	car(string title, int year_of_manufacture, int engine_capacity, double price) {
		this->title = title;
		this->year_of_manufacture = year_of_manufacture;
		this->engine_capacity = engine_capacity;
		this->price = price;
	}

	string get_title() {
		return title;
	}

	int get_year_of_manufacture() {
		return year_of_manufacture;
	}

	int get_engine_capacity() {
		return engine_capacity;
	}

	double get_price() {
		return price;
	}

	static car create_new_car() {
		car c;
		cout << "Title: ";
		getline(cin,c.title);
		cout << "Year of manufacture: ";
		cin >> c.year_of_manufacture;
		cout << "Engine capacity: ";
		cin >> c.engine_capacity;
		cout << "Price: ";
		cin >> c.price;
	}

	void print() {
		cout << title << " | year of manufacture: " << year_of_manufacture << " | engine capacity: " << engine_capacity << " | price: " << price << "\n";

	}
};
