#pragma once
#include <iostream>

#define TEST_MODE

class CFraction {
	int numerator;
	int denumerator;

	void simplify();
	static int gcd(const int a, const int b);

public:
	CFraction();
	//CFraction(std::string str);
	CFraction(const CFraction& f);
	CFraction(int numerator, int denumerator);

	CFraction operator+(const CFraction& frac) const;
	CFraction operator-(const CFraction& frac) const;
	CFraction operator*(const CFraction& frac) const;
	CFraction operator/(const CFraction& frac) const;
	CFraction& operator=(const CFraction& frac);
	CFraction& operator+=(const CFraction& frac);
	CFraction& operator-=(const CFraction& frac);
	CFraction& operator*=(const CFraction& frac);
	CFraction& operator/=(const CFraction& frac);
	CFraction operator+(int value) const;
	CFraction operator-(int value) const;
	CFraction operator*(int value) const;
	CFraction operator/(int value) const;
	CFraction& operator=(int value);
	CFraction& operator+=(int value);
	CFraction& operator-=(int value);
	CFraction& operator*=(int value);
	CFraction& operator/=(int value);

	friend bool operator==(const CFraction& frac1, const CFraction& frac2);
	friend bool operator!=(const CFraction& frac1, const CFraction& frac2);
	friend bool operator<(const CFraction& frac1, const CFraction& frac2);
	friend bool operator<=(const CFraction& frac1, const CFraction& frac2);
	friend bool operator>=(const CFraction& frac1, const CFraction& frac2);
	friend bool operator>(const CFraction& frac1, const CFraction& frac2);
	friend bool operator==(const CFraction& frac1, int value);
	friend bool operator!=(const CFraction& frac1, int value);
	friend bool operator<(const CFraction& frac1, int value);
	friend bool operator<=(const CFraction& frac1, int value);
	friend bool operator>=(const CFraction& frac1, int value);
	friend bool operator>(const CFraction& frac1, int value);
	friend bool operator==(int value, const CFraction& frac1);
	friend bool operator!=(int value, const CFraction& frac1);
	friend bool operator<(int value, const CFraction& frac1);
	friend bool operator<=(int value, const CFraction& frac1);
	friend bool operator>=(int value, const CFraction& frac1);
	friend bool operator>(int value, const CFraction& frac1);
	friend std::ostream& operator<<(std::ostream& out, const CFraction& frac);
	friend std::istream& operator>>(std::istream& in, CFraction& frac);

};