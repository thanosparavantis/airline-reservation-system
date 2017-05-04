#include "NoMem.h"

const char* NoMem::what() const throw()
{
	return "No memory available.";
}