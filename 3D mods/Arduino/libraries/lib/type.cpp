/*
 * type.cpp - Library for extra data types
 * Created by Chonghua Xue, October 19, 2016
 */

#include "type.h"

/******************************************************************************
 * Binary16 defined in IEEE 754
 *****************************************************************************/
Binary16::Binary16(void) {
  //re = 0;
  //im = 0;
}

Binary16::Binary16(float) {
  
}

/*
Float16(double);
~Float16(void);
Float16 operator+(const Float16&);
Float16 operator-(const Float16&);
Float16 operator*(const Float16&);
Float16 operator/(const Float16&);
void operator+=(const Float16&);
void operator-=(const Float16&);
void operator*=(const Float16&);
void operator/=(const Float16&);
void operator=(const Float16&);
float  toFloat(void);
double toDouble(void);
String toString(void);
byte val[2];
*/


/******************************************************************************
 * Complex
 *****************************************************************************/
Complex::Complex(void) {
  re = 0;
  im = 0;
}

Complex::Complex(float _re, float _im) {
  re = _re;
  im = _im;
}

Complex::~Complex(void) {
  // do nothing
}

Complex Complex::operator+(const Complex& o) {
  Complex sum;
  sum.re = re + o.re;
  sum.im = im + o.im;
  return sum;
}

Complex Complex::operator-(const Complex& o) {
  Complex diff;
  diff.re = re - o.re;
  diff.im = im - o.im;
  return diff;
}

Complex Complex::operator*(const Complex& o) {
  Complex prod;
  prod.re = re * o.re - im * o.im;
  prod.im = im * o.re + re * o.im;
  return prod;
}

Complex Complex::operator/(const Complex& o) {
  Complex quot;
  float sq = o.re * o.re + o.im * o.im;
  quot.re = (re * o.re + im * o.im) / sq;
  quot.im = (im * o.re - re * o.im) / sq;
  return quot;
}

void Complex::operator+=(const Complex& o) {
  re = re + o.re;
  im = im + o.im;
}

void Complex::operator-=(const Complex& o) {
  re = re - o.re;
  im = im - o.im;
}

void Complex::operator*=(const Complex& o) {
  float _re = re;
  float _im = im;
  re = _re * o.re - _im * o.im;
  im = _im * o.re + _re * o.im;
}

void Complex::operator=(const Complex& o) {
  re = o.re;
  im = o.im;
}

void Complex::operator/=(const Complex& o) {
  float _re = re;
  float _im = im;
  float sq = o.re * o.re + o.im * o.im;
  re = (_re * o.re + _im * o.im) / sq;
  im = (_im * o.re - _re * o.im) / sq;
}

Complex Complex::conj(void) {
  return Complex(re, -im);
}

float Complex::norm_sq(void) {
  return re * re + im * im;
}

String Complex::toString(void) {
  String str = String('(');
  str.concat(re);
  if (im > 0) {
  	str.concat('+');
  	str.concat(im);
  } else if (im == 0) {
  	str.concat('+');
    str.concat("0.00");
  } else {
  	str.concat(im);
  }
  str.concat("i)");
  return str;
}