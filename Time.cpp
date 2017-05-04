#include "Time.h"

Time::Time(int hour, int minute)
{
	this->hour = hour;
	this->minute = minute;
}

Time::Time() : Time(0, 0)
{

}

int Time::getHour() const
{
	return this->hour;
}

void Time::setHour(int hour)
{
	this->hour = hour;
}

int Time::getMinute() const
{
	return this->minute;
}

void Time::setMinute(int minute)
{
	this->minute = minute;
}

void Time::output(ostream &out) const
{
	string hourDisplay = std::to_string(this->hour);
	if (this->hour < 9) hourDisplay = "0" + std::to_string(this->hour);

	string minuteDisplay = std::to_string(this->minute);
	if (this->minute < 9) minuteDisplay = "0" + std::to_string(this->minute);

	out << hourDisplay << ":" << minuteDisplay;
}
