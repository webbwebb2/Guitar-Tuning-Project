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
    byte& operator[](const byte&);
	void push_back(const byte&);
  private:
    byte* head;
    byte offset;
	byte max_len;
	byte len;
};

#endif
