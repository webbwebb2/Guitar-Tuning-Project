/*
 * dstruct.cpp - Library for mathematical routines
 * Created by Chonghua Xue, October 3, 2016
 */

#ifndef DSTRUCT_H
#define DSTRUCT_H

#include <Arduino.h>

class TrotArray {
  public:
    TrotArray(const byte&);
    float& operator[](const byte&);
	void push_back(const float&);
	const byte& get_len(void);
  private:
    float* head;
    byte offset;
	byte max_len;
	byte len;
};

#endif
