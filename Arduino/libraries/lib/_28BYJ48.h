#ifndef _28BYJ48_H
#define _28BYJ48_H

#define _28BYJ48_SPR 4075.7728395
#define _28BYJ48_SEQ  {B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001}
#define _28BYJ48_SEQ_CCW {B0001, B0011, B0010, B0110, B0100, B1100, B1000, B1001}

#include <Arduino.h>

class _28BYJ48 {
  private:
    int rpm;
	byte pin1;
	byte pin2;
	byte pin3;
	byte pin4;
	const byte seq[8] = _28BYJ48_SEQ;
	float intvl;
	byte nxt_idx;
  public:
    _28BYJ48(const byte&, const byte&, const byte&, const byte&);
    void setRPM(const float& _rpm);
	void rotate(const int& steps);
	void off();
};

#endif