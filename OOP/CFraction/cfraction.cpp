#include "cfraction.hpp"

/**
 * \brief Êîíñòðóêòîð èíèöèàëèçàöèè
 * \param numerator ×èñëèòåëü
 * \param denumerator Çíàìåíàòåëü
 */
CFraction::CFraction(int numerator, int denumerator) {
	this->numerator = numerator;
	this->denumerator = denumerator;
	if (numerator != 0 && denumerator != 0)
		simplify();
}

/**
 * \brief Êîíñòðóêòîð êîïèðîâàíèÿ
 * \param f Ññûëêà íà îáúåêò êëàññà CFraction
 */
CFraction::CFraction(const CFraction& f) :CFraction(f.numerator, f.denumerator) {}

/**
 * \brief Êîíñòðóêòîð ïî óìîë÷àíèþ
 */
CFraction::CFraction() :CFraction(0, 0) {}

/**
 * \brief Ñîêðàùåíèå ñòðîêè
 */
void CFraction::simplify() {
	int gcd = this->gcd(numerator, denumerator);
	numerator /= gcd;
	denumerator /= gcd;
}

/**
 * \brief Ïîèñê ÍÎÄ
 * \param a ×èñëî a
 * \param b ×èñëî b
 * \return ×èñëî ÍÎÄ
 */
int CFraction::gcd(const int a, const int b)
{
	return b == 0 ? a : gcd(b, a % b);
}



CFraction CFraction::operator+(const CFraction& frac) const {
	CFraction res;
	if (this->denumerator == frac.denumerator) {
		res.numerator = this->numerator + frac.numerator;
		res.denumerator = this->denumerator;
	}
	else {
		res.numerator = this->numerator * frac.denumerator +
			frac.numerator * this->denumerator;
		res.denumerator = this->denumerator * frac.denumerator;
	}
	res.simplify();
	return res;
}
CFraction CFraction::operator-(const CFraction& frac) const {
	CFraction res;
	if (this->denumerator == frac.denumerator) {
		res.numerator = this->numerator - frac.numerator;
		res.denumerator = this->denumerator;
	}
	else
	{
		res.numerator = this->numerator * frac.denumerator -
			frac.numerator * this->denumerator;
		res.denumerator = this->denumerator * frac.denumerator;
	}
	res.simplify();
	return res;
}
CFraction CFraction::operator*(const CFraction& frac) const {
	CFraction res;
	res.numerator = this->numerator * frac.numerator;
	res.denumerator = this->denumerator * frac.denumerator;
	res.simplify();
	return res;
}
CFraction CFraction::operator/(const CFraction& frac) const
{
	CFraction res;
	res.numerator = this->numerator * frac.denumerator;
	res.denumerator = this->denumerator * frac.numerator;
	res.simplify();
	return res;
}
CFraction& CFraction::operator=(const CFraction& frac) {
	if (this != &frac)
	{
		this->denumerator = frac.denumerator;
		this->numerator = frac.numerator;
	}
	this->simplify();
	return *this;
}
CFraction& CFraction::operator+=(const CFraction& frac) {
	*this = *this + frac;
	return *this;
}
CFraction& CFraction::operator-=(const CFraction& frac) {
	*this = *this - frac;
	return *this;
}
CFraction& CFraction::operator*=(const CFraction& frac)
{
	*this = *this * frac;
	return *this;
}
CFraction& CFraction::operator/=(const CFraction& frac)
{
	*this = *this / frac;
	return *this;
}
CFraction CFraction::operator+(int value) const
{
	CFraction res;
	res.numerator = value * this->denumerator + this->numerator;
	res.denumerator = this->denumerator;
	res.simplify();
	return res;
}
CFraction CFraction::operator-(int value) const
{
	CFraction res;
	res.numerator = this->numerator - value * this->denumerator;
	res.denumerator = this->denumerator;
	res.simplify();
	return res;
}
CFraction CFraction::operator*(int value) const
{
	CFraction res;
	res.numerator = this->numerator * value;
	res.denumerator = this->denumerator;
	res.simplify();
	return res;
}
CFraction CFraction::operator/(int value) const
{
	CFraction res;
	res.numerator = this->numerator;
	res.denumerator = this->denumerator * value;
	res.simplify();
	return res;
}
CFraction& CFraction::operator=(int value)
{
	this->numerator = value;
	this->denumerator = 1;
	this->simplify();
	return *this;
}
CFraction& CFraction::operator+=(int value)
{
	*this = *this + value;
	return *this;
}
CFraction& CFraction::operator-=(int value)
{
	*this = *this - value;
	return *this;
}
CFraction& CFraction::operator*=(int value)
{
	*this = *this * value;
	return *this;
}
CFraction& CFraction::operator/=(int value)
{
	*this = *this / value;
	return *this;
}


bool operator==(const CFraction& frac1, const CFraction& frac2) {
	if (frac1.numerator == frac2.numerator &&
		frac1.denumerator == frac2.denumerator)
		return true;
	return false;
}
bool operator!=(const CFraction& frac1, const CFraction& frac2)
{
	if (frac1.numerator != frac2.numerator ||
		frac1.denumerator != frac2.denumerator)
		return true;
	return false;
}
bool operator<=(const CFraction& frac1, const CFraction& frac2)
{
	int temp1 = frac1.numerator * frac2.denumerator, temp2 = frac2.numerator * frac1.denumerator;
	if (temp1 <= temp2)
		return true;
	return false;
}
bool operator<(const CFraction& frac1, const CFraction& frac2)
{
	int temp1 = frac1.numerator * frac2.denumerator, temp2 = frac2.numerator * frac1.denumerator;
	if (temp1 < temp2)
		return true;
	return false;
}
bool operator>=(const CFraction& frac1, const CFraction& frac2)
{
	int temp1 = frac1.numerator * frac2.denumerator, temp2 = frac2.numerator * frac1.denumerator;
	if (temp1 >= temp2)
		return true;
	return false;
}
bool operator>(const CFraction& frac1, const CFraction& frac2)
{
	int temp1 = frac1.numerator * frac2.denumerator, temp2 = frac2.numerator * frac1.denumerator;
	if (temp1 > temp2)
		return true;
	return false;
}
bool operator==(const CFraction& frac1, int value)
{
	return frac1.numerator == (value * frac1.denumerator);
}
bool operator!=(const CFraction& frac1, int value)
{
	return frac1.numerator != (value * frac1.denumerator);
}
bool operator<(const CFraction& frac1, int value)
{
	return frac1.numerator < (value * frac1.denumerator);
}
bool operator<=(const CFraction& frac1, int value)
{
	return frac1.numerator <= (value * frac1.denumerator);
}
bool operator>=(const CFraction& frac1, int value)
{
	return frac1.numerator >= (value * frac1.denumerator);
}
bool operator>(const CFraction& frac1, int value)
{
	return frac1.numerator > (value * frac1.denumerator);
}
bool operator==(int value, const CFraction& frac1)
{
	return frac1 == value;
}
bool operator!=(int value, const CFraction& frac1)
{
	return frac1 != value;
}
bool operator<(int value, const CFraction& frac1)
{
	return frac1 > value;
}
bool operator<=(int value, const CFraction& frac1)
{
	return frac1 >= value;
}
bool operator>=(int value, const CFraction& frac1)
{
	return frac1 <= value;

}
bool operator>(int value, const CFraction& frac1)

std::ostream& operator<<(std::ostream& out, const CFraction& frac)
{
	out << frac.numerator << '/' << frac.denumerator;
#ifdef TEST_MODE
	out << '\n';
#endif
	return out;
}
std::istream& operator>>(std::istream& in, CFraction& frac)
{
	char colon;
	in >> frac.numerator >> colon >> frac.denumerator;
	frac.simplify();
	return in;
}