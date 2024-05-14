#pragma once
#include <iostream>
enum status { successful = 0, warning, error };

class c_data {
	int days_;
	int months_;
	int years_;

public:
	c_data(int days, int months, int years);
	c_data(const c_data& t);
	c_data();
	~c_data();

	status assign(c_data* t);
	void input();
	void add_months(int months);
	void add_years(int years);
	void add_days(int days);
	void output(std::string message = "$dd.$mm.$yy");
	void set_values(int days, int months, int years);
	int compare(c_data* t);

private:
	status check();
	status convert();
};