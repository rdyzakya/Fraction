#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
using namespace std;

class Fraction {
private:
	int pembilang;
	int penyebut;
public:
	Fraction();
	Fraction(int pembilang, int penyebut);
	Fraction(const Fraction& other);
	void operator=(const Fraction& other);
	~Fraction();


	friend ostream& operator<<(ostream& out, const Fraction& frac);

	Fraction simplify();

	friend Fraction operator+(const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator+(int my_integer , const Fraction& frac);
	friend Fraction operator+(const Fraction& frac,int my_integer);
	friend float operator+(float my_float , const Fraction& frac);
	friend float operator+(const Fraction& frac,float my_float);

	friend Fraction operator-(const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator-(int my_integer , const Fraction& frac);
	friend Fraction operator-(const Fraction& frac,int my_integer);
	friend float operator-(float my_float , const Fraction& frac);
	friend float operator-(const Fraction& frac,float my_float);

	friend Fraction operator*(const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator*(int my_integer , const Fraction& frac);
	friend Fraction operator*(const Fraction& frac, int my_integer);
	friend float operator*(float my_float , const Fraction& frac);
	friend float operator*(const Fraction& frac , float my_float);

	friend Fraction operator/(const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator/(int my_integer , const Fraction& frac);
	friend Fraction operator/(const Fraction& frac, int my_integer);
	friend float operator/(float my_float , const Fraction& frac);
	friend float operator/(const Fraction& frac , float my_float);

	friend float fr_tofl(const Fraction& frac);

};


#endif