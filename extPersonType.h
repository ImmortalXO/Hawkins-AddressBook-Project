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
	personType(const string& first = "", const string& last = "") : firstName(first), lastName(last) {
	};

	string getLastName() const {
		return lastName;
	};

	string getFirstName() const {
		return firstName;
	};

	void setFirstName(const string& first) {
		firstName = first;
	};


	void setLastName(const string& last) {
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
		const string& street = "", const string& cityName = "", const string& stateName = "XX", int zipcode = 10000,
		const string& phoneNum = "None", const string& rel = "None") : personType(first, last), birthDate(m, d, yr), address(street, cityName, stateName, zipcode),
		phoneNumber(phoneNum), relationship(rel) {
		birthDate.setDate(m, d, yr);
	};

	string getPhoneNumber() const {
		return phoneNumber;
	};

	void setPhoneNumber(string& phoneNum) {
		phoneNumber = phoneNum;
	};

	string getRelationship() const {
		return relationship;
	};

	void setRelationship(const string& rel) {
		if (rel == "Friend" || rel == "Family" || rel == "Business") {
			relationship = rel;
		}
		else {
			relationship = "None";
		}
	};

	int getBirthMonth() const {
		return birthDate.getMonth();
	};

	string getKey() const {
		return getFirstName() + " " + getLastName();
	}
	// Overload the relational operators
	bool operator==(const extPersonType& other) const {
		return getKey() == other.getKey();
	}

	bool operator!=(const extPersonType& other) const {
		return getKey() != other.getKey();
	}

	bool operator>=(const extPersonType& other) const {
		return getKey() >= other.getKey();
	}

	void print() const {
		cout << getKey() << endl;
		birthDate.print();
		address.print();
		cout << "Phone Number: " << phoneNumber << endl;
		cout << "Relationship: " << relationship << endl;
	}
};
