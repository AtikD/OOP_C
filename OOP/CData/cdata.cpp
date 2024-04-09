#include "cdata.hpp"
#include <iostream>
#include <string>

using namespace std;
//Êîíñòðóêòîðû
c_data::c_data(const int days, const int months, const int years) {
	this->days_ = days;
	this->months_ = months;
	this->years_ = years;
	this->convert();
}
c_data::c_data(const c_data& t) : c_data(t.days_, t.months_, t.years_) {}
c_data::c_data() : c_data(0, 0, 0) {}

c_data::~c_data() {}

//Ôóíêöèè
void c_data::output(std::string message) {
	message.replace(message.find("$dd"), 3, to_string(this->days_));
	message.replace(message.find("$mm"), 3, to_string(this->months_));
	message.replace(message.find("$yy"), 3, to_string(this->years_));
	cout << message + "\n";

}

status c_data::check() {
	status state = successful;
	if ((this->months_ > 12 || this->months_ < 1) ||
		(this->days_ > 30 || this->days_ < 1))
		state = error;
	return state;
}


void c_data::input() {
	char colon;
	cout << "\nWrite the date(dd.mm.yy): ";
	cin >> this->days_ >> colon
		>> this->months_ >> colon
		>> this->years_;
	this->convert();
	this->output("successfully read: $dd.$mm.$yy");
}


void c_data::set_values(int days, int months, int years) {
	this->days_ = days;
	this->months_ = months;
	this->years_ = years;
	this->convert();
	this->output("successfully set: $dd.$mm.$yy");

}

status c_data::convert() {
	status state = successful;
	if (this->check() == successful)
		return state;
	while (true) {
		if (this->days_ > 30) {
			this->days_ -= 30;
			this->months_++;
			continue;
		} if (this->months_ > 12) {
			this->months_ -= 12;
			this->years_++;
			continue;
		}
		break;
	}
	return state;
}

void c_data::add_days(int days) {
	this->days_ += days;
	this->convert();
	this->output("successfully added: $dd:$mm:$yy");
}

void c_data::add_months(int months) {
	this->add_days(months * 30);
}

void c_data::add_years(int years) {
	this->add_days(years * 12 * 30);
}

status c_data::assign(c_data* t) {
	status state = successful;
	if (t == nullptr)
		state = error;
	else {
		t->days_ = this->days_;
		t->months_ = this->months_;
		t->years_ = this->years_;
	}
	return state;
}

int c_data::compare(c_data* t) {
	int days1 = 0, days2 = 0;
	days1 += this->years_;
	days1 += this->months_ * 30;
	days1 += this->days_ * 12 * 30;

	days2 += t->years_;
	days2 += t->months_ * 30;
	days2 += t->days_ * 12 * 30;

	if (days1 > days2) {
		return 1;
	}
	if (days1 < days2)
	{
		return -1;
	}
	if (days1 == days2) {
		return 0;
	}
}