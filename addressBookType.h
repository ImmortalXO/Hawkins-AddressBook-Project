#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "extPersonType.h"
#include "orderedLinkedList.h"
using namespace std;

class addressBookType : public orderedLinkedList<extPersonType>
{
private:
public:
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


    // Function to save address book data to a file.
    // Formal parameters: const string& fileName
    // User input(s): File name to save the address book data.
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: Output file exists and is accessible.
    // Postconditions: Writes address book data to the specified file, overwriting existing data if the file already exists.
    void saveInfoToFile(const string& fileName) const {
        ofstream outputFile(fileName);
        nodeType<extPersonType>* current = first;
        if (!outputFile.is_open()) {
            cerr << "Error opening the data file for writing.";
        };

        while (current != nullptr) {
            outputFile << current->info.getFirstName() << " " << current->info.getLastName() << endl;
            outputFile << current->info.getBirthMonth() << " " << current->info.getBirthDate().getDay() << " " << current->info.getBirthDate().getYear() << endl;
            outputFile << current->info.getAddress().getStreet() << endl;
            outputFile << current->info.getAddress().getCity() << endl;
            outputFile << current->info.getAddress().getState() << endl;
            outputFile << current->info.getAddress().getZipcode() << endl;
            outputFile << current->info.getPhoneNumber() << endl;
            outputFile << current->info.getRelationship() << endl;
            current = current->link;
        }

        cout << "Data has been successfully saved to " << fileName << endl;

        outputFile.close();
    } 

    // Function to add an entry to the address book
    // Formal parameters: const extPersonType& person
    // User inputs: extPersonType object
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Adds the provided extPersonType object to the address book if there is space available.
    void addEntry(const extPersonType& person) {
        this->insert(person);
    };

    // Function to add a new entry to the address book.
    // Formal parameters: None
    // User inputs: firstName, lastName, birthMonth, birthDay, birthYear, streetName, cityName, stateName, zipcode, phoneNumber, relationship
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Adds a new person object to the address book with the provided information.
    void addNewEntry() {
        string firstName, lastName, street, cityName, stateName, phoneNumber, relationship;
        int birthMonth, birthDay, birthYear, zipcode;

        cout << "Enter a first name: ";
        cin >> firstName;
        cout << "Enter a last name: ";
        cin >> lastName;
        cout << "Enter a birth month: ";
        cin >> birthMonth;
        cout << "Enter a birth day: ";
        cin >> birthDay;
        cout << "Enter a birth year: ";
        cin >> birthYear;
        cout << "Enter a street name: ";
        cin.ignore();
        getline(cin, street);
        cout << "Enter a city name: ";
        getline(cin, cityName);
        cout << "Enter a state name (Two Letter Abbr.): ";
        getline(cin, stateName);
        cout << "Enter a zipcode: ";
        cin >> zipcode;
        cout << "Enter a phone number: ";
        cin >> phoneNumber;
        cout << "Enter a relationship: ";
        cin.ignore();
        getline(cin, relationship);

        extPersonType newPerson(firstName, lastName, birthMonth, birthDay, birthYear, street, cityName, stateName, zipcode, phoneNumber, relationship);

        insert(newPerson);
        
        cout << "You have added a new Person!" << endl;

    }

    // Function to remove an entry from the address book.
    // Formal parameters: None
    // User inputs: firstName, lastName
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Removes the person with the provided first name and last name from the address book if found; otherwise, throws an error message.

    void removeNewEntry() {
        string firstName, lastName, key;

        cout << "Enter the first name of the person you want to remove: ";
        cin >> firstName;

        cout << "Enter the last name of the person you want to remove: ";
        cin >> lastName;

        key = firstName + " " + lastName;

        bool found = false;
        nodeType<extPersonType>* current = first;
        nodeType<extPersonType>* trail = nullptr;
        while (current != nullptr) {
            if (current->info.getKey() == key) {
                found = true;
                break;
            }
            trail = current;
            current = current->link;
        }

        if (found) {
            if (current == first) {
                first = first->link;
            }
            else {
                trail->link = current->link;
            }
            deleteNode(key);
            cout << key << " has been removed." << endl;
        }
        else {
            cout << "Could not find a person with the name of: " << key << endl;
        }
    }

    // Function to find a person by last name and print their details
    // Formal parameters: const string& last
    // User inputs: Last name of the person to find
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the details of the person with the specified last name if found.
    void findPerson(const string& name) const {
        bool found = false;
        nodeType<extPersonType> *current = first;
        while (current != nullptr) {
            string key = current->info.getFirstName() + " " + current->info.getLastName();
            if (key == name) {
                current->info.print();
                found = true;
                break;
            }
            current = current->link;

        }
        if (!found) {
            cout << "Could not find a person with the name of: " << name << endl;
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
        nodeType<extPersonType>* current = first;
        while (current != nullptr) {
            if (current->info.getBirthMonth() == mon) {
                current->info.print();
                found = true;
                break;
            }
            current = current->link;
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
        nodeType<extPersonType>* current = first;
        while (current != nullptr) {
            if (current->info.getRelationship() == relation) {
                current->info.print();
                found = true;
                break;
            }
            current = current->link;
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
        nodeType<extPersonType>* current = first;
        while (current != nullptr) {
            current->info.print();
            current = current->link;
        }
    };
};

