#include "Car.h"
car::car() {}

car::car(string title, int year_of_manufacture, int engine_capacity, double price) {
	this->title = title;
	this->year_of_manufacture = year_of_manufacture;
	this->engine_capacity = engine_capacity;
	this->price = price;
}

string car::get_title() const {
	return title;
}

int car::get_year_of_manufacture() const {
	return year_of_manufacture;
}

int car::get_engine_capacity() const {
	return engine_capacity;
}

double car::get_price() const {
	return price;
}

car car::create_new_car() {
	car c;
	cout << "Title: ";
	getline(cin, c.title);
	cout << "Year of manufacture: ";
	cin >> c.year_of_manufacture;
	cout << "Engine capacity: ";
	cin >> c.engine_capacity;
	cout << "Price: ";
	cin >> c.price;
	return c;
}

void car::print() const {
	cout << title << " | year of manufacture: " << year_of_manufacture << " | engine capacity: " << engine_capacity << " | price: " << price << "\n";

}