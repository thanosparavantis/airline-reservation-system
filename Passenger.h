#pragma once

#include <iostream>
#include <string>

using namespace std;

class Passenger
{
private:
	string firstname;
	string lastname;
	int passportNumber;
	string nationality;
	string address;
	int telephone;

public:
	Passenger(string firstname, string lastname, int passportNumber, string nationality, string address, int telephone);
	Passenger();
	string getFirstName() const;
	void setFirstName(string firstname);
	string getLastName() const;
	void setLastName(string lastname);
	string getFullName() const;
	int getPassportNumber() const;
	void setPassportNumber(int passportNumber);
	string getNationality() const;
	void setNationality(string nationality);
	string getAddress() const;
	void setAddress(string address);
	int getTelephone() const;
	void setTelephone(int telephone);
	void output(ostream &out) const;
	bool operator==(const Passenger& other) const;
	bool operator!=(const Passenger& other) const;
};