#pragma once
#include <iostream>
#include <string>
#include <fstream>
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

	void initEntry(string fileName) {
		ifstream inFile (fileName);
		if (!inFile) {
			cerr << "Error opening the data file.";
		};

		while (inFile) {
			string firstName, lastName;
			int month, day, year;
			string street, city, state;
			int zipcode;
			string phoneNumber, relationship;

			inFile >> firstName >> lastName >> month >> day >> year;
			inFile >> street >> city >> state >> zipcode;
			inFile >> phoneNumber >> relationship;

			extPersonType person(firstName, lastName, month, day, year, street, city, state, zipcode, phoneNumber, relationship);
			addEntry(person);
		}
		inFile.close();
	};

	void addEntry(extPersonType person) {
		if (length < maxLength) {
			addressList[length] = person;
			length++;
		};
	};

	void findPerson(string last) {
		for (int i = 0; i < length; i++) {
			if (addressList[i].getLastName() == last) {
				addressList[i].print();
			}
		}
	};

	void findBirthdays(int mon) {
		for (int i = 0; i < length; i++) {
			if (addressList[i].getBirthMonth() == mon) {
				addressList[i].print();
			}
		}
	};

	void findRelations(string relation) {
		for (int i = 0; i < length; i++) {
			if (addressList[i].getRelationship() == relation) {
				addressList[i].print();
			}
		}
	};

	void print() const {
		for (int i = 0; i < length; i++) {
			addressList[i].print();
		}
	};

	void sortEntries() {
		bool placeFound;
		for (int i = 1; i < length; i++) {
			extPersonType current = addressList[i].getLastName();
			int j = i - 1;
			placeFound = false;
			while (j >= 0 && !placeFound) {
				addressList[j + 1] = addressList[j];
				j--;
			}
			addressList[j + 1] = current;
		}
	}

};

