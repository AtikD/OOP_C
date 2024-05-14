#pragma once
#include <iostream>
enum Status { Successful = 0, Warning, Error };

class CTime {
	int hours;
	int minutes;
	int seconds;

public:
	CTime(int hours, int minutes, int seconds);
	CTime(const CTime* t);
	CTime();

	Status assign(CTime* t);
	void input();
	void add_minutes(int minutes);
	void add_seconds(int seconds);
	void add_hours(int hours);
	void output(std::string message = "$hh:$mm:$ss");
	void set_values(int hours, int minutes, int seconds);
	int compare(CTime* t);

private:
	Status check();
	Status convert();
};