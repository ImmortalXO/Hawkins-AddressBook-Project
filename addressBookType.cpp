#include "addressBookType.h"
#include <iostream>
#include <string>

using namespace std;

int showMenu() {
	int choice;
	cout << "--------------------" << endl;
	cout << "Address Book Menu" << endl;
	cout << "--------------------" << endl;
	cout << "Select an option:" << endl;
	cout << "--------------------" << endl;
	cout << "1. Find By Person" << endl;
	cout << "2. Find By Birth Month" << endl;
	cout << "3. Find By Relationship" << endl;
	cout << "4. Add a New Entry" << endl;
	cout << "5. Remove an Entry" << endl;
	cout << "6. Quit" << endl;
	cout << "--------------------" << endl;
	cout << "Choice: ";
	cin >> choice;
	return choice;
};

int main() {
	addressBookType obj;
	obj.initEntry("addressBookData.txt");
	int choice;
	do {
		choice = showMenu();
		switch (choice) {
		case 1: {
			string first, last;
			cout << "Enter the first name of the person you want to find: ";
			cin >> first;
			cout << "Enter the last name of the person you want to find: ";
			cin >> last;
			string key = first + " " + last;
			obj.findPerson(key);
			break;
		}
		case 2: {
			int month;
			cout << "Enter the birth month of the person you want to find: ";
			cin >> month;
			obj.findBirthdays(month);
			break;
		}
		case 3: {
			string relationship;
			cout << "Enter the relationship of the person you want to find: ";
			cin >> relationship;
			obj.findRelations(relationship);
			break;
		}
		case 4: {
			obj.addNewEntry();
		}
		case 5: {
			obj.removeNewEntry();
		}
		case 6: {
			break;
		}
		default:
			cout << "Invalid choice." << endl;
		}
	} while (choice != 7);
};