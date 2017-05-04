#pragma once

#include <iostream>
#include <exception>

using namespace std;

class NoMem : public exception
{
public:
	const char * what() const throw();
};