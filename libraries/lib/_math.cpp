/*
 * _math.cpp - Library for mathematical routines
 * Created by Chonghua Xue, October 19, 2016
 */

#include "_math.h"

Complex* dft(const Complex* vec_in, int dim) {
  // allocate memory for output vector
  Complex* vec_out = NULL;
  if (!(vec_out = malloc_arr_c(dim)))	
  	return NULL;
  // calc and return
  Complex temp;
  float c = (-2) * PI / dim;
  for (int k = 0; k < dim; k++)
  	for (int n = 0; n < dim; n++) {
  	  temp = vec_in[n];
      vec_out[k] += temp * exp_c(Complex(0, c * k * n));
  	}
  return vec_out;
}

int _dft(Complex* vec, int dim) {
  // allocate memory for output vector
  Complex* vec_out = NULL;
  if (!(vec_out = malloc_arr_c(dim)))	
  	return 1;
  // calculation
  float c = (-2) * PI / dim;
  for (int k = 0; k < dim; k++)
  	for (int n = 0; n < dim; n++)
      vec_out[k] += vec[n] * exp_c(Complex(0, c * k * n));
  // assign result to vec & memory release 
  for (int k = 0; k < dim; k++)
  	vec[k] = vec_out[k];
  free(vec_out);
  return 0;
}

Complex* fft_dit2(const Complex* vec_in, int dim) {
  // do DFT if the dimemsion of input vector is NOT dividable by 2
  if (dim % 2 != 0)
  	return dft(vec_in, dim);
  // divide input vector into 2 (dim/2)-D vector, even & odd
  int _dim = dim / 2;
  Complex* vec_in_e = NULL;
  Complex* vec_in_o = NULL;
  if (!(vec_in_e = malloc_arr_c(_dim)) || 
  	  !(vec_in_o = malloc_arr_c(_dim))
  )	return NULL;
  for (int m = 0; m < _dim; m++) {
  	vec_in_e[m] = vec_in[2 * m];
  	vec_in_o[m] = vec_in[2 * m + 1];
  }
  // recursive process
  Complex* vec_out_e = fft_dit2(vec_in_e, _dim);
  Complex* vec_out_o = fft_dit2(vec_in_o, _dim);
  // combine into output vector
  Complex* vec_out = NULL;
  if (!(vec_out = malloc_arr_c(dim)))
  	return NULL;
  float c1 = (-2) * PI / dim;
  for (int m = 0; m < _dim; m++) {
  	Complex c2 = exp_c(Complex(0, c1 * m)) * vec_out_o[m];
  	vec_out[m]        = vec_out_e[m] + c2;
  	vec_out[m + _dim] = vec_out_e[m] - c2;
  }
  // free memory and return
  free(vec_in_e);
  free(vec_in_o);
  free(vec_out_e);
  free(vec_out_o);
  return vec_out;
}

int _fft_dit2(Complex* vec, int dim) {
  if (dim % 2 != 0)
  	return _dft(vec, dim);
  int _dim = dim / 2;
  // sort into even & odd clusters
  Complex* vec_half = NULL;
  if (!(vec_half = malloc_arr_c(_dim)))
  	return 1;
  for (int m = 0; m < _dim; m++)
  	vec_half[m] = vec[2 * m + 1];
  for (int m = 1; m <= _dim; m++)
  	vec[m] = vec[2 * m];
  for (int m = 0; m < _dim; m++)
  	vec[m + _dim] = vec_half[m];
  free(vec_half);
  // recursive process
  if (_fft_dit2(vec       , _dim)) return 1;
  if (_fft_dit2(vec + _dim, _dim)) return 1;
  // output
  float c1 = (-2) * PI / dim;
  if (!(vec_half = malloc_arr_c(_dim)))
  	return 1;
  for (int m = 0; m < _dim; m++)
  	vec_half[m] = exp_c(Complex(0, c1 * m)) * vec[m + _dim];
  for (int m = 0; m < _dim; m++)  // second half
  	vec[m + _dim] = vec[m] - vec_half[m];
  for (int m = 0; m < _dim; m++)  // first half
  	vec[m] = vec[m] + vec_half[m];
  free(vec_half);
  return 0;
}

Complex exp_c(const Complex& expo) {
  float a    = exp(expo.re);
  float b_re = cos(expo.im);
  float b_im = sin(expo.im);
  return Complex(a * b_re, a * b_im);
}