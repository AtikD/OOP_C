#include "cdata.hpp"
#include <iostream>


int main() {
	c_data t1;
	t1.output();
	std::cout << "\n";

	c_data t2(1, 6, 2005);
	t2.output();
	std::cout << "\n";

	c_data t3(t2);
	t3.output();
	std::cout << "\n";

	t1.set_values(21, 76, 22);
	t1.output();
	std::cout << "\n";

	t3.input();
	t3.output();
	std::cout << "\n";

	t2.add_days(5);
	t2.add_months(20);
	t2.add_years(10);
	t2.output();
	std::cout << "\n";

	t3.assign(&t1); // copy values from t3 to t1
	t1.output();
	std::cout << "\n";

	std::cout << t2.compare(&t1);

	return 1;
}