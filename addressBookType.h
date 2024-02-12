#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "extPersonType.h"
using namespace std;

class addressBookType
{
private:
	extPersonType addressList[500];
	int length;
	int maxLength;
public:
	addressBookType() {
		length = 0;
		maxLength = 500;
	}

	void initEntry(const string &fileName) {
		ifstream inFile (fileName);
		if (!inFile) {
			cerr << "Error opening the data file.";
		};

		string line;
		while (getline(inFile, line)) {
			string firstName, lastName, street, city, state, phoneNumber, relationship;
			int month, day, year, zipcode;

			istringstream iss(line);
			iss >> firstName >> lastName;
			inFile >> month >> day >> year;
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(inFile, street);
			getline(inFile, city);
			inFile >> state >> zipcode;
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(inFile, phoneNumber);
			getline(inFile, relationship);

			extPersonType person(firstName, lastName, month, day, year, street, city, state, zipcode, phoneNumber, relationship);
			addEntry(person);
		}
		inFile.close();
	};

	void addEntry(const extPersonType &person) {
		if (length < maxLength) {
			addressList[length] = person;
			length++;
		};
	};

	void findPerson(const string &last) const {
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (addressList[i].getLastName() == last) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Could not find a person with the last name of: " << last << endl;
		}
	};

	void findBirthdays(int mon) const {
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (addressList[i].getBirthMonth() == mon) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Could not find a person with the birth month of: " << mon << endl;
		}
	};

	void findRelations(const string &relation) const {
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (addressList[i].getRelationship() == relation) {
				addressList[i].print();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Could not find a person with the relationship of: " << relation << endl;
		}
	};

	void print() const {
		for (int i = 0; i < length; i++) {
			addressList[i].print();
		}
	};

	void sortEntries() {
		for (int i = 1; i < length; i++) {
			extPersonType current = addressList[i];
			bool placeFound = false;
			int j = i - 1;
			while (j >= 0 && !placeFound) {
				if (addressList[j].getLastName() > current.getLastName()) {
					addressList[j + 1] = addressList[j];
					j--;
				}
				else {
					placeFound = true;
				};
			};
			addressList[j + 1] = current;
		};
	};
};

