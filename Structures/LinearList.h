#pragma once

#include <iostream>
#include "LinearList.h"
#include "../Exceptions/NoMem.h"
#include "../Exceptions/OutOfBounds.h"

using namespace std;

// Σημείωση: Δεν μπορούμε να χρησιμοποιήσουμε αρχείο .cpp μαζί με .h όταν η κλάση έχει template.
// Οπότε ο ορισμός των μεθόδων βρίσκεται εδώ.

template <class T>
class LinearList
{
private:
	int maxSize;
	T *element;
	int size;
public:
	LinearList(int maxSize = 10);
	~LinearList();
	LinearList(const LinearList<T>& other);
	LinearList<T>& operator= (const LinearList<T>& other);
	bool isEmpty() const;
	int length() const;
	bool find(int k, T& x) const;
	int search(const T& x) const;
	void remove(int k, T& x);
	void insert(int k, const T& x);
	void insert(const T& x);
	void replace(int k, const T& x);
	void output(ostream& out) const;
};

template<class T>
LinearList<T>::LinearList(int maxSize = 10) : maxSize(maxSize), element(new T[maxSize]), size(0)
{

}

// Επειδή χειριζόμαστε δυναμικά τον πίνακα χρειαζόμαστε:
// - Copy constructor
// - Assignment operator
// - Destructor
// Πολύ καλή τεκμηρίωση του ζητήματος στο Stack Overflow (http://stackoverflow.com/a/4172724/2672192)

// Copy constructor
template<class T>
LinearList<T>::LinearList(const LinearList<T>& other)
{
	// Αντιγράφουμε όλα τα δεδομένα της μιας κλάσης στην άλλη σε άλλες θέσης μνήμης.

	this->maxSize = other.maxSize;

	this->element = new T[other.maxSize];

	for(int i = 0; i < other.size; i++)
	{
		this->element[i] = other.element[i];
	}

	this->size = other.size;
}

// Assignment operator
template<class T>
LinearList<T>& LinearList<T>::operator= (const LinearList<T>& other)
{
	// Αντιγράφουμε όλα τα δεδομένα της μιας κλάσης στην άλλη σε άλλες θέσης μνήμης.

	this->maxSize = other.maxSize;

	delete[] this->element;

	this->element = new T[other.maxSize];

	for (int i = 0; i < other.size; i++)
	{
		this->element[i] = other.element[i];
	}

	this->size = other.size;
	return *this;
}

// Destructor
template<class T>
LinearList<T>::~LinearList()
{
	delete[] this->element;
}

template<class T>
bool LinearList<T>::isEmpty() const
{
	return this->size == 0;
}

template<class T>
int LinearList<T>::length() const
{
	return this->size;
}

template<class T>
bool LinearList<T>::find(int k, T& x) const
{
	if (k < 1 || k > this->size)
		return false;

	x = this->element[k - 1];

	return true;
}

template<class T>
int LinearList<T>::search(const T& x) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->element[i] == x)
			return ++i;
	}

	return 0;
}

template<class T>
void LinearList<T>::remove(int k, T& x)
{
	if (this->find(k, x))
	{
		for (int i = k; i < this->size; i++)
		{
			this->element[i - 1] = this->element[i];
		}

		this->size--;
	}
	else
	{
		throw OutOfBounds();
	}
}

template<class T>
void LinearList<T>::insert(int k, const T& x)
{
	if (k < 0 || k > this->size)
		throw OutOfBounds();

	if (this->size == this->maxSize)
		throw NoMem();

	for (int i = this->size - 1; i >= k; i--)
	{
		this->element[i + 1] = this->element[i];
	}

	this->element[k] = x;
	this->size++;
}

template<class T>
void LinearList<T>::insert(const T& x)
{
	// Επειδή μπορεί να θέλουμε να εισάγουμε στοιχείο χωρίς να μας απασχολεί
	// το index του πίνακα απλά κάνουμε εισαγωγή στο τέλος του.

	if (this->size == this->maxSize)
		throw NoMem();

	this->element[this->size] = x;
	this->size++;
}

template<class T>
void LinearList<T>::replace(int k, const T& x)
{
	if (k < 0 || k > this->size)
		throw OutOfBounds();

	this->element[k] = x;
}

template<class T>
void LinearList<T>::output(ostream& out) const
{
	for (int i = 0; i < this->size; i++)
	{
		this->element[i].output(out);
		cout << endl;
	}
}
