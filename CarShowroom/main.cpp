#include "CarShowroom.h"

fstream& operator>>(fstream& fin, car& c) {
	fin >>c.id>> c.title >> c.year_of_manufacture >> c.engine_capacity >> c.price;
	replace(c.title.begin(), c.title.end(), '_', ' ');
	return fin;
}
fstream& operator<<(fstream& fout, car& c) {
	string tmp_t = c.title;
	replace(tmp_t.begin(), tmp_t.end(), ' ', '_');
	fout <<c.id<<" " << tmp_t << " " << c.year_of_manufacture << " " << c.engine_capacity << " " << c.price << "\n";
	return fout;
}

int main() {
	CarShowroom cs("save.txt");

	do {
		int choice;
		cout << "1. Print all\n";
		cout << "2. Add car\n";
		cout << "3. Delete by title\n";
		cout << "4. Descending sort\n";
		cout << "5. Ascending Sort\n";
		cout << "6. Find by title\n";
		cout << "7. Save\n";
		(cin>>choice).get();
		if (choice == 0)
			break;

		switch (choice) {
		case 1:
			cs.print_all();
			break;
		case 2:
			cs.add_car();
			break;
		case 3: {
			int id;
			cout << "Enter id: ";
			(cin >> id).get();
			cs.delete_by_id(id);
		}break;
		case 4:
			cs.sorting([](const car& one, const car& two) {return one.get_price() > two.get_price(); });
			break;
		case 5:
			cs.sorting([](const car& one, const car& two) {return one.get_price() < two.get_price(); });
			break;
		case 6: {
			int id;
			cout << "Enter id: ";
			(cin >> id).get();
			cout << "\n\n";
			cs.search([id](const car& c) {return c.get_id() == id; }).print();
			cout << "\n\n";
		}break;
		case 7:
			cs.save();
			break;
			
		}
	} while (true);

	return 0;
}