/*
 * _math.h - Library for mathematical routines
 * Created by Chonghua Xue, October 19, 2016
 */

#ifndef _MATH_H
#define _MATH_H

#include "type.h"
#include "util.h"

Complex* dft(const Complex*, int);
Complex* fft_dit2(const Complex*, int);
Complex  exp_c(const Complex&);
int      _dft(Complex*, int);
int      _fft_dit2(Complex*, int);

#endif