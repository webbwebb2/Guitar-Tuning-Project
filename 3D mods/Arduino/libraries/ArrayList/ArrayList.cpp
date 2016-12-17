#include "ArrayList.h"

ArrayList::ArrayList(const char _dtype) {
  int blen = 1;
  dtype = _dtype;
    switch (_dtype) {
      case 'b': blen = 1; break;  // byte | unsigned 8-bit int
      case 'B': blen = 1; break;  // boolean
      case 'c': blen = 1; break;  // char
      case 'C': blen = 1; break;  // unsigned char
      case 'i': blen = 2; break;  // signed int
      case 'I': blen = 2; break;  // unsigned int
      case 'w': blen = 2; break;  // word | unsigned int (16-bit on Uno)
      case 's': blen = 2; break;  // short 16-bit
      case 'l': blen = 4; break;  // long
      case 'L': blen = 4; break;  // unsigned long
      case 'f': blen = 4; break;  // float 32-bit
      case 'd': blen = 8; break;  // double 64-bit
      default: break;             // default 8-bit
  }

  // allocate memory
  hptr = 
}

ArrayList::~ArrayList(void) {

}

int ArrayList::add() {

}

int ArrayList::print() {

}
