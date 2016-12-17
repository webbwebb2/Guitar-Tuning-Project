/*
 * Math.h - Library for general routines
 * Created by Chonghua Xue, October 19, 2016
 */
#include "util.h"

Complex* malloc_arr_c(int dim) {
  Complex* vec = (Complex*)malloc(dim * sizeof(Complex));
  if (vec == NULL) {
  	Serial.println("malloc_arr_c: fail to allocate memory.");
  	return NULL;
  }
  // initialize with all 0s
  for (int k = 0; k < dim; k++) {
  	vec[k].re = 0;
  	vec[k].im = 0;
  }
  return vec;
}
