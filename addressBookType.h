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
    // Constructor
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Initializes the address book with empty values.
    addressBookType();

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

    void saveInfoToFile(const string &fileName) const {
        ofstream outputFile(fileName);
        nodeType<extPersonType>* current = first;
        if (!outputFile.is_open()) {
            cerr << "Error opening the data file for writing.";
        };

        while (current != nullptr) {
            outputFile << current->info.getFirstName() << " "
                << current->info.getLastName() << " "
                << current->info.getBirthMonth() << " "
                << current->info.getBirthDay() << " "
                << current->info.getBirthYear() << " "
                << current->info.getPhoneNumber() << " "
                << current->info.getRelationship() << " "
                << current->info.getAddress().getStreet() << " "
                << current->info.getAddress().getCity() << " "
                << current->info.getAddress().getState() << " "
                << current->info.getZipCode() << endl;
            current = current->link;
        }
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
        cout << "Enter a state name: ";
        getline(cin, stateName);
        cout << "Enter a zipcode: ";
        cin >> zipcode;
        cout << "Enter a phone number: ";
        cin >> phoneNumber;
        cout << "Enter a relationship: ";
        cin.ignore();
        getline(cin, relationship);

        extPersonType newPerson(firstName, lastName, birthMonth, birthDay, birthYear, street, cityName, stateName, zipcode, phoneNumber, relationship);

        this->insert(newPerson);
        
        cout << "You have added a new Person!" << endl;

    }

    void removeNewEntry() {
        string firstName, lastName, fullName;
        cout << "Enter the first name of the person you want to remove: ";
        cin >> firstName;
        cout << "Enter the last name of the person you want to remove: ";
        cin >> lastName;
        string fullName = firstName + " " + lastName;

        if (this->search(fullName)) {
            this->deleteNode(fullName);
            cout << "Deleted the person with the name: " << fullName << endl;
        }
        else {
            cout << "Could not find person with the name: " << endl;
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
            cout << "Could not find a person with the last name of: " << name << endl;
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

