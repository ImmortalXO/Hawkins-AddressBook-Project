#pragma once
#include <iostream>
#include <cassert>

using namespace std;
class dateType
{
private:
	int dMonth;
	int dDay;
	int dYear;
public:
    // Accessor function to get the day
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: day
    // Preconditions: None
    // Postconditions: Returns the day component of the date.
    int getDay() const { return dDay; }

    // Accessor function to get the month
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: month
    // Preconditions: None
    // Postconditions: Returns the month component of the date.
    int getMonth() const { return dMonth; }

    // Accessor function to get the year
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: year
    // Preconditions: None
    // Postconditions: Returns the year component of the date.
    int getYear() const { return dYear; }

    dateType() {
        dMonth = 1;
        dDay = 1;
        dYear = 1900;
    }

    // Constructor with parameters
    // Formal parameters: int month, int day, int year
    // User inputs: month, day, year
    // Supplied constants: N/A
    // Outputs: None
    // Preconditions: None
    // Postconditions: Initializes the object with the specified date or 1/1/1900
    // if the date is invalid.
    dateType(int month, int day, int year) { setDate(month, day, year); }

    // Function to set the date
    // Formal parameters: int month, int day, int year
    // User inputs: month, day, year
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Sets the object's date to the specified values or 1/1/1900
    // if the values are invalid.
    void setDate(int month, int day, int year) {
        bool isInvalidDate = false;

        if (year >= 1900) {
            dYear = year;
        }
        else {
            isInvalidDate = true;
            dYear = 1900;
            dMonth = 1;
            dDay = 1;
        }

        if (month >= 1 && month <= 12) {
            dMonth = month;
        }
        else {
            isInvalidDate = true;
            dMonth = 1;
            dDay = 1;
            dYear = 1900;
        }

        int getLastDayOfMonth = 0;
        if (month == 2 && isLeapYear(dYear)) {
            getLastDayOfMonth = 29;
        }
        else if (month == 2) {
            getLastDayOfMonth = 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            getLastDayOfMonth = 30;
        }
        else {
            getLastDayOfMonth = 31;
        }

        if (day >= 1 && day <= getLastDayOfMonth) {
            dDay = day;
        }
        else {
            isInvalidDate = true;
            dDay = 1;
            dMonth = 1;
            dYear = 1900;
        }

        if (isInvalidDate) {
            cout << "Date invalid, setting to 1/1/1900" << endl;
        }
    };

    // Function to check if a year is a leap year
    // Formal parameters: int year
    // User inputs: year
    // Supplied constants: None
    // Outputs: boolean: true if the year is a leap year, false if not
    // Preconditions: year should be non-negative.
    // Postconditions: Returns true if the year is a leap year, false otherwise.
    bool isLeapYear(int year) {
        assert(year >= 0);
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    };

    // Function to print the date
    // Formal parameters: None
    // User inputs: None
    // Supplied constants: None
    // Outputs: None
    // Preconditions: None
    // Postconditions: Prints the date to the standard output.
    void print() const { cout << dMonth << "-" << dDay << "-" << dYear << endl; }
};

