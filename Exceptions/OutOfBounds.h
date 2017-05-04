#pragma once

#include <iostream>
#include <exception>

using namespace std;

class OutOfBounds : public exception
{
public:
	const char * what() const throw();
};
