#include "ctime.hpp"
#include <iostream>
#include <string>

using namespace std;
//Êîíñòðóêòîðû
CTime::CTime(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	this->convert();
}
CTime::CTime(const CTime* t) : CTime(t->hours, t->minutes, t->seconds) {}
CTime::CTime() : CTime(0, 0, 0) {}
//Ôóíêöèè
void CTime::output(std::string message) {
	message.replace(message.find("$hh"), 3, to_string(this->hours));
	message.replace(message.find("$mm"), 3, to_string(this->minutes));
	message.replace(message.find("$ss"), 3, to_string(this->seconds));
	cout << message << endl;

}

Status CTime::check() {
	Status state = Successful;
	if ((this->seconds > 60 || this->seconds < 1) ||
		(this->minutes > 60 || this->minutes < 1) ||
		(this->hours > 24 || this->hours < 1))
		state = Error;
	return state;
}


void CTime::input() {
	char colon;
	cout << endl << "Write the time(hh:mm:ss): ";
	cin >> this->hours >> colon
		>> this->minutes >> colon
		>> this->seconds;
	this->convert();
	this->output("Successfully read: $hh:$mm:$ss");
}


void CTime::set_values(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	this->convert();
	this->output("Successfully set: $hh:$mm:$ss");

}

Status CTime::convert() {
	Status state = Successful;
	if (this->check() == Successful)
		return state;
	while (true) {
		if (this->seconds > 60) {
			this->seconds -= 60;
			this->minutes++;
			continue;
		}
		else if (this->minutes > 60) {
			this->minutes -= 60;
			this->hours++;
			continue;
		}
		else if (this->hours > 24) {
			this->hours -= 24;
			state = Warning;
		}
		else
			break;
	}
	return state;
}

void CTime::add_hours(int hours) {
	this->hours += hours;
	this->convert();
	this->output("Successfully added hours: $hh:$mm:$ss");
}

void CTime::add_minutes(int minutes) {
	this->minutes += minutes;
	this->convert();
	this->output("Successfully added minutes: $hh:$mm:$ss");
}

void CTime::add_seconds(int seconds) {
	this->seconds += seconds;
	this->convert();
	this->output("Successfully added seconds: $hh:$mm:$ss");
}

Status CTime::assign(CTime* t) {
	Status state = Successful;
	if (t == nullptr)
		state = Error;
	else {
		t->hours = this->hours;
		t->minutes = this->minutes;
		t->seconds = this->seconds;
	}
	return state;
}

int CTime::compare(CTime* t) {
	int secs1 = 0, secs2 = 0;
	secs1 += this->seconds;
	secs1 += this->minutes * 60;
	secs1 += this->hours * 60 * 60;

	secs2 += t->seconds;
	secs2 += t->minutes * 60;
	secs2 += t->hours * 60 * 60;

	if (secs1 > secs2) {
		return 1;
	}
	if (secs1 < secs2)
	{
		return -1;
	}
	if (secs1 == secs2) {
		return 0;
	}
}