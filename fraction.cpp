#include "fraction.hpp"
#include <iostream>
using namespace std;

Fraction::Fraction() {
	pembilang = 0;
	penyebut = 1;
}

Fraction::Fraction(int pembilang, int penyebut) {
	this->pembilang = pembilang;
	if (penyebut == 0)
	{
		this->penyebut = 1;
	}else this->penyebut = penyebut;
}

Fraction::Fraction(const Fraction& other) {
	this->pembilang = other.pembilang;
	this->penyebut = other.penyebut;
}

void Fraction::operator=(const Fraction& other) {
	this->pembilang = other.pembilang;
	this->penyebut = other.penyebut;
}

Fraction::~Fraction() { }

ostream& operator<<(ostream& out, const Fraction& frac) {
	if (frac.pembilang == 0)
	{
		out << 0;
	}else if (frac.penyebut == 1)
	{
		out << frac.pembilang;
	}
	else{
		out << frac.pembilang << "/" << frac.penyebut;
	}
	return out;
}

Fraction Fraction::simplify(){
	int fpb;
	if (this->penyebut < this->pembilang)
	{
		fpb = this->penyebut;
	}else fpb = this->pembilang;
	while(fpb > 0 && (this->penyebut%fpb != 0 || this->pembilang%fpb != 0)) {
		fpb--;
	}
	this->penyebut /= fpb;
	this->pembilang /= fpb;
	return *this;
}

Fraction operator+(const Fraction& frac1 , const Fraction& frac2) {
	int newpembilang = frac1.pembilang*frac2.penyebut + frac2.pembilang*frac1.penyebut;
	int newpenyebut = frac1.penyebut*frac2.penyebut;
	return Fraction(newpembilang,newpenyebut).simplify();
}

Fraction operator+(int my_integer , const Fraction& frac) {
	int newpembilang = my_integer*frac.penyebut + frac.pembilang;
	return Fraction(newpembilang,frac.penyebut).simplify();;
}

Fraction operator+(const Fraction& frac,int my_integer) {
	int newpembilang = my_integer*frac.penyebut + frac.pembilang;
	return Fraction(newpembilang,frac.penyebut).simplify();
}

float operator+(float my_float , const Fraction& frac) {
	return fr_tofl(frac) + my_float;
}

float operator+(const Fraction& frac,float my_float) {
	return fr_tofl(frac) + my_float;
}

Fraction operator-(const Fraction& frac1 , const Fraction& frac2) {
	int newpembilang = frac1.pembilang*frac2.penyebut - frac2.pembilang*frac1.penyebut;
	int newpenyebut = frac1.penyebut*frac2.penyebut;
	return Fraction(newpembilang,newpenyebut).simplify();
}

Fraction operator-(int my_integer , const Fraction& frac) {
	int newpembilang = my_integer*frac.penyebut - frac.pembilang;
	return Fraction(newpembilang,frac.penyebut).simplify();
}

Fraction operator-(const Fraction& frac,int my_integer) {
	int newpembilang = my_integer*frac.penyebut - frac.pembilang;
	return Fraction(newpembilang,frac.penyebut).simplify();
}

float operator-(float my_float , const Fraction& frac) {
	return fr_tofl(frac) - my_float;
}

float operator-(const Fraction& frac,float my_float) {
	return my_float - fr_tofl(frac);
}

Fraction operator*(const Fraction& frac1 , const Fraction& frac2) {
	return Fraction(frac1.pembilang*frac2.pembilang , frac1.penyebut*frac2.penyebut).simplify();
}

Fraction operator*(int my_integer , const Fraction& frac) {
	return Fraction(frac.pembilang*my_integer , frac.penyebut).simplify();
}

Fraction operator*(const Fraction& frac, int my_integer) {
	return Fraction(frac.pembilang*my_integer , frac.penyebut).simplify();
}

float operator*(float my_float , const Fraction& frac) {
	return fr_tofl(frac)*my_float;
}

float operator*(const Fraction& frac , float my_float) {
	return fr_tofl(frac)*my_float;
}


Fraction operator/(const Fraction& frac1 , const Fraction& frac2) {
	Fraction inverted2(frac2.penyebut,frac2.pembilang);
	return frac1 * inverted2;
}

Fraction operator/(int my_integer , const Fraction& frac) {
	Fraction inverted2(frac.penyebut,frac.pembilang);
	return my_integer * inverted2;
}

Fraction operator/(const Fraction& frac, int my_integer) {
	Fraction inverted2(1,my_integer);
	return frac * inverted2;
}

float operator/(float my_float , const Fraction& frac){
	return my_float / fr_tofl(frac);
}

float operator/(const Fraction& frac , float my_float){
	return fr_tofl(frac) / my_float;
}

float fr_tofl(const Fraction& frac) {
	return float(frac.pembilang)/float(frac.penyebut);
}