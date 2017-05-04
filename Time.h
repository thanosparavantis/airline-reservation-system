#pragma once
#include <iostream>
#include <string>

using namespace std;

// Η κλασή αυτή λειτουργεί ως βοηθητική της κλάσης Flight ώστε να αποφύγουμε
// την αποθήκευση string, καθώς θα ήταν δύσκολη η επεξεργασία του.

class Time
{
private:
	int hour;
	int minute;

public:
	Time(int hour, int minute = 0);
	Time();
	int getHour() const;
	void setHour(int hour);
	int getMinute() const;
	void setMinute(int minute);
	void output(ostream &out) const;
};