#pragma once

#include "Node.h"

// Σημείωση: Δεν μπορούμε να χρησιμοποιήσουμε αρχείο .cpp μαζί με .h όταν η κλάση έχει template.
// Οπότε ο ορισμός των μεθόδων βρίσκεται εδώ.

template<class T>
class LinkedQueue
{
private:
	Node<T> *front, *rear;
	int size;
public:
	LinkedQueue();
	bool isEmpty() const;
	void first(T& x) const;
	void last(T& x) const;
	int length() const;
	bool search(const T x) const;
	int operator+(T x);
	int operator-(T& x);
};

template<class T>
LinkedQueue<T>::LinkedQueue() : front(0), rear(0), size(0)
{

}

template<class T>
bool LinkedQueue<T>::isEmpty() const
{
	return front ? false : true;
}

template<class T>
void LinkedQueue<T>::first(T& x) const
{
	x = this->front->data;
}

template<class T>
void LinkedQueue<T>::last(T& x) const
{
	x = this->rear->data;
}

template<class T>
int LinkedQueue<T>::length() const
{
	return this->size;
}

template<class T>
bool LinkedQueue<T>::search(const T x) const
{
	// Αναζήτηση στοιχείου στην ουρά.
	// Ελέγχουμε από την αρχή μέχρι το τέλος το data όλων των κόμβων.

	if (this->size > 0)
	{
		Node<T> *pointer = this->front;
		bool found = (pointer->data == x);

		while (pointer->link)
		{
			found = (pointer->link->data == x);
			pointer = pointer->link;
		}

		return found;
	}
	
	return false;
}

template<class T>
int LinkedQueue<T>::operator+ (T x)
{
	Node<T> *i = new Node<T>;

	if (i)
	{
		i->data = x;
		i->link = 0;

		if (this->front)
			this->rear->link = i;
		else
			this->front = i;

		this->rear = i;

		this->size++;

		return 1;
	}

	return 0;
}

template<class T>
int LinkedQueue<T>::operator- (T& x)
{
	if (this->isEmpty())
		return 0;
	
	x = this->front->data;
	
	Node<T> *i = this->front;
	front = this->front->link;
	delete i;

	this->size--;

	return 1;
}