#include "Passenger.h"

Passenger::Passenger(string firstname, string lastname, int passportNumber, string nationality, string address, int telephone) : firstname(firstname), lastname(lastname), passportNumber(passportNumber), nationality(nationality), address(address), telephone(telephone)
{

}

Passenger::Passenger() : Passenger("", "", 0, "", "", 0)
{

}

string Passenger::getFirstName() const
{
	return this->firstname;
}

void Passenger::setFirstName(string firstname)
{
	this->firstname = firstname;
}

string Passenger::getLastName() const
{
	return this->lastname;
}

void Passenger::setLastName(string lastname)
{
	this->lastname = lastname;
}

string Passenger::getFullName() const
{
	return this->firstname + " " + this->lastname;
}

int Passenger::getPassportNumber() const
{
	return this->passportNumber;
}

void Passenger::setPassportNumber(int passportNumber)
{
	this->passportNumber = passportNumber;
}

string Passenger::getNationality() const
{
	return this->nationality;
}

void Passenger::setNationality(string nationality)
{
	this->nationality = nationality;
}

string Passenger::getAddress() const
{
	return this->address;
}

void Passenger::setAddress(string address)
{
	this->address = address;
}

int Passenger::getTelephone() const
{
	return this->telephone;
}

void Passenger::setTelephone(int telephone)
{
	this->telephone = telephone;
}

void Passenger::output(ostream &out) const
{
	out << "Name: " << this->getFullName() << endl;
	out << "Address: " << this->address << " Tel.: " << this->telephone << endl;
	out << "Nationality: " << this->nationality << endl;
	out << "Passport Number: " << this->passportNumber << endl;
}

bool Passenger::operator==(const Passenger& other) const
{
	return this->firstname == other.firstname && this->lastname == other.lastname && this->passportNumber == other.passportNumber;
}

bool Passenger::operator!=(const Passenger& other) const
{
	return this->firstname != other.firstname || this->lastname != other.lastname || this->passportNumber != other.passportNumber;
}