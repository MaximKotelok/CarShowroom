#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class car {
	int id;
	string title;
	int year_of_manufacture;
	int engine_capacity;
	double price;

public:
	car();

	car(int id, string title, int year_of_manufacture, int engine_capacity, double price);
	
	int get_id() const;

	string get_title() const;

	int get_year_of_manufacture() const;

	int get_engine_capacity() const;

	double get_price() const;

	static car create_new_car(int id);

	void print() const;

	friend fstream& operator>>(fstream& fin, car& c);
	friend fstream& operator<<(fstream& fout, car& c);

};
