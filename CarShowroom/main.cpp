#include <conio.h>
#include "CarShowroom.h"
#include "MenuElement.h"

fstream& operator>>(fstream& fin, car& c);

fstream& operator<<(fstream& fout, car& c);

ostream& operator<<(ostream& os, car& c);

void set_elements(vector<menu_element>& elements);

int main() {
	try {

	CarShowroom cs("save.txt");
	int old_index = -1;
	int index = 0;
	int key;

	vector<menu_element> elements;
	set_elements(elements);

	cout << "*" << string(50, '=') << "*\n";
	cout << "STEP CAR SHOWROOM\n";
	cout << "We have " << cs.get_size() << " cars\n";
	cout << "The total cost of which is " << cs.get_total_cost() << "\n";
	cout << "*" << string(50, '=') << "*\n";

	cout << "\n!Menu control button!\n!down, up - navigation!\n!Space, enter - select!\n";
	system("pause");
	system("cls");
	do {
		old_index = -1;
		do {
			if (old_index != index) {

				for (int i = 0; i < elements.size(); i++) {
					if (index != i)
						elements[i].print();
					else
						elements[i].print_active();

				}
			}
			old_index = index;
			key = _getch();
			switch (key) {
			case 72:
				if (index - 1 < 0)
					index = elements.size() - 1;
				else
					index--;
				break;
			case 80:
				if (index + 1 >= elements.size())
					index = 0;
				else
					index++;
				break;
			}

		system("cls");
		} while (key != 13 && key != 32);
		if (index == 0)
			break;

		elements[index].start(cs);
		system("pause");
		system("cls");
	} while (true);
	}
	catch (FileNotOpenException exp) {
		cout << exp.what() << " | path: " << exp.get_path() << "\n";
	}
	return 0;
}

fstream& operator>>(fstream& fin, car& c) {
	fin >> c.id >> c.title >> c.year_of_manufacture >> c.engine_capacity >> c.price;
	replace(c.title.begin(), c.title.end(), '_', ' ');
	return fin;
}
fstream& operator<<(fstream& fout, car& c) {
	string tmp_t = c.title;
	replace(tmp_t.begin(), tmp_t.end(), ' ', '_');
	fout << c.id << " " << tmp_t << " " << c.year_of_manufacture << " " << c.engine_capacity << " " << c.price << "\n";
	return fout;
}

ostream& operator<<(ostream& os, car& c) {
	os << c.id << ". " << c.title << " | year of manufacture: " << c.year_of_manufacture << " | engine capacity: " << c.engine_capacity << " | price: " << c.price << "\n";
	return os;
}

void set_elements(vector<menu_element>& elements) {
	elements.push_back({ "Exit", [](CarShowroom& cs) {} });
	elements.push_back({ "Print all", [](CarShowroom& cs) {cs.print_all(); } });
	elements.push_back({ "Add car", [](CarShowroom& cs) {cs.add_car(); } });
	elements.push_back({ "Delete by id", [](CarShowroom& cs) {
			int id;
			cout << "Enter id: ";
			(cin >> id).get();
			cs.delete_by_id(id); } });
	elements.push_back({ "Descending sort", [](CarShowroom& cs) {cs.sorting([](const car& one, const car& two) {return one.get_price() > two.get_price(); }); } });
	elements.push_back({ "Ascending Sort", [](CarShowroom& cs) {cs.sorting([](const car& one, const car& two) {return one.get_price() < two.get_price(); }); } });
	elements.push_back({ "Sort by id", [](CarShowroom& cs) {cs.sorting([](const car& one, const car& two) {return one.get_id() < two.get_id(); }); } });
	elements.push_back({ "Find by id", [](CarShowroom& cs) {
			int id;
			cout << "Enter id: ";
			(cin >> id).get();
			cout << "\n\n";
			cs.search([id](const car& c) {return c.get_id() == id; }).print();
			cout << "\n\n";
			} });
	elements.push_back({ "Save", [](CarShowroom& cs) {cs.save(); } });

}