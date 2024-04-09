#include "ctime.hpp"
#include <iostream>


void main() {
	CTime t1;
	t1.output(); // 0:0:0
	std::cout << std::endl;

	CTime t2(15, 25, 58);
	t2.output(); // 15:25:58
	std::cout << std::endl;

	CTime t3(&t2);
	t3.output(); // 15:25:58
	std::cout << std::endl;

	t1.set_values(21, 76, 22);
	t1.output(); // 22:16:22
	std::cout << std::endl;

	t3.input(); // input from keyboard
	t3.output(); // 15:25:58
	std::cout << std::endl;

	t2.add_hours(5); // t2 is 20:25:58
	t2.add_minutes(20); // t2 is 20:45:58
	t2.add_seconds(10); // t2 is 20:46:8
	t2.output(); // 15:25:58
	std::cout << std::endl;

	t3.assign(&t1); // copy values from t3 to t1
	t1.output(); // 15:25:58
	std::cout << std::endl;

	std::cout << t2.compare(&t1); // compares the time, 1 if t2 >> t1, -1 if t2 << t1, 0 if t1==t2
}