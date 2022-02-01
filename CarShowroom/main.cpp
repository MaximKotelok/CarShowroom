#include "CarShowroom.h"

int main() {
	CarShowroom cs;

	do {
		int choice;
		cout << "1. Print all\n";
		cout << "2. Add car\n";
		cout << "3. Delete by title\n";
		cout << "4. Descending sort\n";
		cout << "5. Ascending Sort\n";
		cout << "6. Find by title\n";
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
			string title;
			cout << "Enter title: ";
			getline(cin, title);
			cs.delete_by_title(title);
		}break;
		case 4:
			cs.sorting([](const car& one, const car& two) {return one.get_price() > two.get_price(); });
			break;
		case 5:
			cs.sorting([](const car& one, const car& two) {return one.get_price() < two.get_price(); });
			break;
		case 6: {
			string title;
			cout << "Enter title: ";
			getline(cin, title);
			cout << "\n\n";
			cs.search([title](const car& c) {return c.get_title() == title; }).print();
		}break;
			
		}
	} while (true);

	return 0;
}