#pragma once
#include "Time.h"
#include "Structures\LinearList.h"
#include "Structures\LinkedQueue.h"
#include "Passenger.h"

class Flight
{
private:
	string code;
	string origin;
	string destination;
	Time departureTime;
	Time arrivalTime;
	double ticketPrice;
	string airplaneType;
	int airplaneSeats;
	int reservations;
	LinearList<Passenger> passengers;
	LinkedQueue<Passenger> queue;

public:
	Flight(string code, string origin, string destination, Time departureTime, Time arrivalTime, double ticketPrice, string airplaneType, int airplaneSeats, int reservations);
	Flight();
	string getCode() const;
	void setCode(string code);
	string getOrigin() const;
	void setOrigin(string origin);
	string getDestination() const;
	void setDestination(string destination);
	Time getDepartureTime() const;
	void setDepartureTime(Time departureTime);
	Time getArrivalTime() const;
	void setArrivalTime(Time arrivalTime);
	double getTicketPrice() const;
	void setTicketPrice(double ticketPrice);
	string getAirplaneType() const;
	void setAirplaneType(string airplaneType);
	int getAirplaneSeats() const;
	void setAirplaneSeats(int airplaneSeats);
	int getReservations() const;
	void setPassengers(LinearList<Passenger> passengers);
	LinearList<Passenger> getPassengers() const;
	void setReservations(int reservations);
	LinkedQueue<Passenger> getQueue() const;
	void setQueue(LinkedQueue<Passenger> queue);
	void output(ostream &out) const;
	bool isInOrderWith(Flight next) const;
	bool isFull() const;
	bool hasPassenger(Passenger passenger) const;
};