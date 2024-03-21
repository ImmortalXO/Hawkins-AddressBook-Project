#pragma once
#include <iostream>
#include <string>
using namespace std;

class addressType
{
private:
	string address;
	string city;
	string state;
	int zipcode;
public:
	addressType(const string& street = "", const string& cityName = "", const string& stateName = "XX", int zip = 10000) {
		address = street;
		city = cityName;
		setState(stateName);
		setZipcode(zip);  
	}

	string getStreet() { return address; };
	string getCity() { return city; };
	string getState() { return state; };
	int getZipcode() { return zipcode; };

	// Setter for streetAddress
	// Formal parameters: street
	// User inputs: street
	// Supplied constants: None
	// Outputs: None
	// Preconditions: None
	// Postconditions: streetAddress is set to the input parameter 'street'
	void setAddress(const string& street) { address = street; }

	// Setter for city
	// Formal parameters: cityName
	// User inputs: cityName
	// Supplied constants: None
	// Outputs: None
	// Preconditions: None
	// Postconditions: city is set to the input parameter 'cityName'
	void setCity(const string& cityName) { city = cityName; }

	// Setter for state
	// Formal parameters: stateName
	// User inputs: stateName
	// Supplied constants: None
	// Outputs: None
	// Preconditions: None
	// Postconditions: state is set to 'stateName' if it is a valid 2-character
	// state code; otherwise, set to default "XX"
	void setState(const string& stateName) {
		if (stateName.length() == 2) {
			state = stateName;
		}
		else {
			state = "XX";
		}
	}

	// Setter for zipcode
	// Formal parameters: zip
	// User inputs: zip
	// Supplied constants: None
	// Outputs: None
	// Preconditions: None
	// Postconditions: zipcode is set to 'zip' if it is in the valid range [10000,
	// 99999]; otherwise, set to default 10000
	void setZipcode(int zip) {
		if (zip >= 10000 && zip <= 99999) {
			zipcode = zip;
		}
		else {
			zipcode = 10000;
		}
	}

	// Display address details
	// Formal parameters: None
	// User inputs: None
	// Supplied constants: None
	// Outputs: None
	// Preconditions: None
	// Postconditions: Address details are printed to the console
	void print() const {
		cout << address << endl;
		cout << city << " " << state << ", " << zipcode << endl;
	}
};

