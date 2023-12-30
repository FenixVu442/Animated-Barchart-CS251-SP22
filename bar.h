/*
* File: bar.h
* Project 3 - Animated Bar Chart
* Date: 02/17/2022
* Manh Vu Bui
* vub2
*/

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
private:
	string name;
	string country = "N/A";
	int value;
	string category;

public:

	// default constructor:
	Bar() {
		name = "";
		value = 0;
		category = "";
	}

	//
	// a second constructor:
	//
	// Parameter passed in constructor Bar object.
	//
	Bar(string name, int value, string category) {
		this->name = name;
		this->value = value;
		this->category = category;
	}

	// destructor:
	virtual ~Bar() {
		// TO DO:  Write this destructor or leave empty if not needed.
	}

	// getName:
	string getName() const {
		return name;
	}

	// getValue:
	int getValue() const {
		return value;
	}

	// getCategory:
	string getCategory() const {
		return category;
	}

	// setCountry:
	void setCountry(string country) {
		this->country = country;
	}

	// getCountry:
	string getCountry() const {
		return country;
	}

	// operators
	// TO DO:  Write these operators.  This allows you to compare two Bar
	// objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar& other) const {
		return this->value < other.value;
	}

	bool operator<=(const Bar& other) const {
		return !(this->value > other.value);
	}

	bool operator>(const Bar& other) const {
		return this->value > other.value;
	}

	bool operator>=(const Bar& other) const {
		return !(this->value < other.value);
	}
};

