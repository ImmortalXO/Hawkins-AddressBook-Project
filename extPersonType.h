#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include "addressType.h"
#include "dateType.h"
using namespace std;

class personType
{
private:
    string firstName;
    string lastName;

public:
    // Constructor
    // Formal parameters: const string& first, const string& last
    // User inputs: first name, last name
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Initializes firstName and lastName with provided values or empty strings.
    personType(const string& first = "", const string& last = "") : firstName(first), lastName(last) {}

    // Getter function for last name
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: lastName
    // Preconditions: None
    // Postconditions: Returns the lastName attribute.
    string getLastName() const { return lastName; }

    // Getter function for first name
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: firstName
    // Preconditions: None
    // Postconditions: Returns the firstName attribute.
    string getFirstName() const { return firstName; }

    // Setter function for first name
    // Formal parameters: const string& first
    // User inputs: firstName
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Updates the firstName attribute with the provided value.
    void setFirstName(const string& first) { firstName = first; }

    // Setter function for last name
    // Formal parameters: const string& last
    // User inputs: lastName
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Updates the lastName attribute with the provided value.
    void setLastName(const string& last) { lastName = last; }
};

class extPersonType : public personType
{
private:
    addressType address;
    dateType birthDate;
    string phoneNumber;
    string relationship;

public:
    // Constructor with parameters
    // Formal parameters: const string& first, const string& last, int m, int d, int yr, const string& street, const string& cityName, const string& stateName, int zipcode, const string& phoneNum, const string& rel
    // User inputs: first name, last name, birth date (month, day, year), address details (street, city name, state name, zipcode), phone number, relationship
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Initializes the object with the specified values.
    extPersonType(const string& first = "", const string& last = "", int m = 1, int d = 1, int yr = 1900,
        const string& street = "", const string& cityName = "", const string& stateName = "XX", int zipcode = 10000,
        const string& phoneNum = "None", const string& rel = "None") : personType(first, last), birthDate(m, d, yr), address(street, cityName, stateName, zipcode),
        phoneNumber(phoneNum), relationship(rel) {
        birthDate.setDate(m, d, yr);
    }

    // Getter function for phone number
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: phoneNumber
    // Preconditions: None
    // Postconditions: Returns the phoneNumber attribute.
    string getPhoneNumber() const { return phoneNumber; }

    // Setter function for phone number
    // Formal parameters: string& phoneNum
    // User inputs: phone number
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Updates the phoneNumber attribute with the provided value.
    void setPhoneNumber(string& phoneNum) { phoneNumber = phoneNum; }

    // Getter function for relationship
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: relationship
    // Preconditions: None
    // Postconditions: Returns the relationship attribute.
    string getRelationship() const { return relationship; }

    // Setter function for relationship
    // Formal parameters: const string& rel
    // User inputs: relationship
    // Supplied constants: None
    // Outputs: None
    // Preconditions: rel must be one of "Friend", "Family", or "Business"
    // Postconditions: Updates the relationship attribute with the provided value if valid.
    void setRelationship(const string& rel) { if (rel == "Friend" || rel == "Family" || rel == "Business") { relationship = rel; } else { relationship = "None"; } }

    // Getter function for birth month
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: month component of birth date
    // Preconditions: None
    // Postconditions: Returns the month component of the birthDate attribute.
    int getBirthMonth() const { return birthDate.getMonth(); }

    // Print function
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the object's attributes including first name, last name, birth date, address details, phone number, and relationship.
    void print() const { cout << getFirstName() << " " << getLastName() << endl; birthDate.print(); address.print(); cout << "Phone Number: " << phoneNumber << endl; cout << "Relationship: " << relationship << endl; }
};
