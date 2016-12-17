/*
 * type.h - Library for extra data types
 * Created by Chonghua Xue, October 19, 2016
 */

#ifndef TYPE_H
#define TYPE_H

#include <Arduino.h>

class Binary16 {
  public:
  	Binary16(void);
  	Binary16(float);
  	Binary16(double);
  	~Binary16(void);
  	Binary16 operator+(const Binary16&);
  	Binary16 operator-(const Binary16&);
  	Binary16 operator*(const Binary16&);
  	Binary16 operator/(const Binary16&);
  	void operator+=(const Binary16&);
    void operator-=(const Binary16&);
    void operator*=(const Binary16&);
    void operator/=(const Binary16&);
    void operator=(const Binary16&);
    float  toFloat(void);
    double toDouble(void);
    String toString(void);
    short val;
};

class Complex {
  public:
    Complex(void);
  	Complex(float _re, float _im);
  	~Complex(void);
  	Complex operator+(const Complex&);
  	Complex operator-(const Complex&);
  	Complex operator*(const Complex&);
  	Complex operator/(const Complex&);
    void operator+=(const Complex&);
    void operator-=(const Complex&);
    void operator*=(const Complex&);
    void operator/=(const Complex&);
    void operator=(const Complex&);
    Complex conj(void);
    float norm_sq(void);
  	String toString(void);
  	float re;
  	float im;
};

#endif