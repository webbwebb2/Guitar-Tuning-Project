/*
 * dstruct.cpp - Library for mathematical routines
 * Created by Chonghua Xue, October 19, 2016
 */
 
#include "dstruct.h"

TrotArray::TrotArray(const byte& _max_len) {
  max_len = _max_len;
  offset  = 0;
  len     = 0;
  
  // alloc mem by given len
  head = (byte*)malloc(len * sizeof(byte));
  if (head == NULL)
    Serial.println("TrotArray::TrotArray: fail to allocate memory.");
}

byte& TrotArray::operator[](const byte& index) {
  if (index >= len || index < 0)
    Serial.println("TrotArray::operator[]: out of index.");
  return head[(index + offset) % max_len];
}

void TrotArray::push_back(const byte& val) {
  if (len < max_len) {
    head[len++] = val;
  } else {
	head[offset++] = val;
    if (offset == max_len)
      offset = 0;
  }
}
