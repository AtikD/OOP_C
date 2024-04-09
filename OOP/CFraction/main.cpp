#include "cfraction.hpp"

int main() {
	CFraction f1(1, 4), f2(2, 3), f3(4, 2);
	CFraction f4 = f2;
	CFraction f5{ 3,5 };
	CFraction f6 = f4 + f5;
	CFraction f7 = f4 - f5;
	f4 += f5;
	f4 -= f5;
	CFraction f8(2, 8);
	//std::cout << f1 << f2  << f3 << f4 << f5 << f6 << f7 << f4 << f8;
	//std::cout << (f2 == f3) << (f2 != f3) << (f2 >= f5) << (f2 <= f5) << (f2 > f5) << (f2 < f5);
	//std::cout << (f8 == 1) << (1 == f8) << (f8 > 1) << (f8 < 2) << (f8 < 0) << (0 > f8);
	//std::cout << (f8 + f5) << (f8-f5) << (f8 * f5) << (f8 / f5);
	//std::cout << (f8 + 5) << (f8 - 5) << (f8 * 5) << (f8 / 5);
	/*
	f1 += f8;
	f2 -= f8;
	f3 *= f8;
	f5 /= f8;

	f1 += 5;
	f2 -= 2;
	f3 *= 5;
	f5 /= 2;
	*/
	//std::cin >> f1;
	return 0;
}