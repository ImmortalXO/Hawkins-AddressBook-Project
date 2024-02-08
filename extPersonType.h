#pragma once
#include <iostream>
#include <string>
#include "addressType.h"
#include "dateType.h"
using namespace std;

class personType
{
private:
	string firstName;
	string lastName;
public:
	personType(const string &first = "", const string& last = "") {
		firstName = first;
		lastName = last;
	};

	string getLastName() {
		return lastName;
	};

	string getFirstName() {
		return firstName;
	};

	void setFirstName(string& first) {
		firstName = first;
	};


	void setLastName(string& last) {
		lastName = last;
	};
};

class extPersonType: public personType 
{
private:
	addressType address;
	dateType birthDate;
	string phoneNumber;
	string relationship;
public:
	extPersonType(const string& first = "", const string& last = "", int m = 1, int d = 1, int yr = 1900, 
	const string &street = "", const string &cityName = "", const string &stateName = "XX", int zipcode = 10000, 
	const string &phoneNum = "None", const string &rel = "None") {

	}

	string getPhoneNumber() {
		return phoneNumber;
	};

	void setPhoneNumber(string& phoneNum) {
		phoneNumber = phoneNum;
	};

	string getRelationship() {
		return relationship;
	};

	void setRelationship(string& rel) {
		if (rel == "Friend" || rel == "Family" || rel == "Business") {
			relationship = rel;
		}
	};

	int getBirthMonth() {
		return birthDate.getMonth();
	};

	void print() {
		cout << personType::getFirstName() << " " << personType::getLastName() << endl;
		birthDate.print();
		address.print();
		cout << "Phone Number: " << phoneNumber << endl;
		cout << "Relationship: " << relationship << endl;
	}
};
