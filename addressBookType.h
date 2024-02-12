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
    // Constructor
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Initializes the address book with empty values.
    addressBookType() {
        length = 0;
        maxLength = 500;
    }

    // Function to read entries from a file and initialize the address book
    // Formal parameters: const string& fileName
    // User inputs: File name containing address book data
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: File exists and is accessible.
    // Postconditions: Reads data from the file, creates extPersonType objects, and adds them to the address book.
    void initEntry(const string& fileName) {
        ifstream inFile(fileName);
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
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the whitespace
            getline(inFile, street);
            getline(inFile, city);
            inFile >> state >> zipcode;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the whitespace
            getline(inFile, phoneNumber);
            getline(inFile, relationship);

            extPersonType person(firstName, lastName, month, day, year, street, city, state, zipcode, phoneNumber, relationship);
            addEntry(person);
        }
        inFile.close();
    };

    // Function to add an entry to the address book
    // Formal parameters: const extPersonType& person
    // User inputs: extPersonType object
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Adds the provided extPersonType object to the address book if there is space available.
    void addEntry(const extPersonType& person) {
        if (length < maxLength) {
            addressList[length] = person;
            length++;
        };
    };

    // Function to find a person by last name and print their details
    // Formal parameters: const string& last
    // User inputs: Last name of the person to find
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the details of the person with the specified last name if found.
    void findPerson(const string& last) const {
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

    // Function to find persons with birthdays in a given month and print their details
    // Formal parameters: int mon
    // User inputs: Month number
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the details of persons with birthdays in the specified month if found.
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

    // Function to find persons with a given relationship and print their details
    // Formal parameters: const string& relation
    // User inputs: Relationship type
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the details of persons with the specified relationship if found.
    void findRelations(const string& relation) const {
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

    // Function to print all entries in the address book
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the details of all entries in the address book.
    void print() const {
        for (int i = 0; i < length; i++) {
            addressList[i].print();
        }
    };

    // Function to sort the entries in the address book by last name
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Sorts the entries in the address book by last name.
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

