#include "Flight.h"

Flight::Flight(string code, string origin, string destination, Time departureTime, Time arrivalTime, double ticketPrice, string airplaneType, int airplaneSeats, int reservations) : code(code), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime), ticketPrice(ticketPrice), airplaneType(airplaneType), airplaneSeats(airplaneSeats), reservations(reservations), passengers(LinearList<Passenger>(airplaneSeats)), queue(LinkedQueue<Passenger>())
{

}

Flight::Flight() : Flight("", "", "", Time(), Time(), 0.0, "", 0, 0)
{

}

string Flight::getCode() const
{
	return this->code;
}

void Flight::setCode(string code)
{
	this->code = code;
}

string Flight::getOrigin() const
{
	return this->origin;
}

void Flight::setOrigin(string origin)
{
	this->origin = origin;
}

string Flight::getDestination() const
{
	return this->destination;
}

void Flight::setDestination(string destination)
{
	this->destination = destination;
}

Time Flight::getDepartureTime() const
{
	return this->departureTime;
}

void Flight::setDepartureTime(Time departureTime)
{
	this->departureTime = departureTime;
}

Time Flight::getArrivalTime() const
{
	return this->arrivalTime;
}

void Flight::setArrivalTime(Time arrivalTime)
{
	this->arrivalTime = arrivalTime;
}

double Flight::getTicketPrice() const
{
	return this->ticketPrice;
}

void Flight::setTicketPrice(double ticketPrice)
{
	this->ticketPrice = ticketPrice;
}

string Flight::getAirplaneType() const
{
	return this->airplaneType;
}

void Flight::setAirplaneType(string airplaneType)
{
	this->airplaneType = airplaneType;
}

int Flight::getAirplaneSeats() const
{
	return this->airplaneSeats;
}

void Flight::setAirplaneSeats(int airplaneSeats)
{
	this->airplaneSeats = airplaneSeats;
}

int Flight::getReservations() const
{
	return this->reservations;
}

void Flight::setReservations(int reservations)
{
	this->reservations = reservations;
}

LinearList<Passenger> Flight::getPassengers() const
{
	return this->passengers;
}

void Flight::setPassengers(LinearList<Passenger> passengers)
{
	this->passengers = passengers;
	this->reservations = passengers.length();
}

LinkedQueue<Passenger> Flight::getQueue() const
{
	return this->queue;
}

void Flight::setQueue(LinkedQueue<Passenger> queue)
{
	this->queue = queue;
}

void Flight::output(ostream &out) const
{
	string price = to_string(this->ticketPrice);

	while (price.find(".") != string::npos && (price.substr(price.length() - 1, 1) == "0" || price.substr(price.length() - 1, 1) == "."))
	{
		price.pop_back();
	}

	out << this->code << ". " << this->origin << " (";
	this->departureTime.output(out);
	out << ") -> " + this->destination << " (";
	this->arrivalTime.output(out);
	out << "), Plane: " << this->airplaneType << ", Ticket: " << price << "$, Seats: " << std::to_string(this->reservations) << "/" << std::to_string(this->airplaneSeats) << ", Queue: " << this->queue.length() << ".";
}

bool Flight::isInOrderWith(Flight next) const
{
	return this->destination == next.getOrigin() &&
		this->departureTime.getHour() < next.getDepartureTime().getHour() &&
		this->arrivalTime.getHour() <= next.getDepartureTime().getHour() &&
		this->departureTime.getMinute() <= next.getDepartureTime().getMinute() &&
		this->arrivalTime.getMinute() <= next.getArrivalTime().getMinute();
}

bool Flight::isFull() const
{
	return this->reservations >= this->airplaneSeats;
}

bool Flight::hasPassenger(Passenger passenger) const
{
	return this->passengers.search(passenger) != 0 || this->queue.search(passenger);
}