#include <_28BYJ48.h>

_28BYJ48::_28BYJ48(
  const byte& _pin1, 
  const byte& _pin2, 
  const byte& _pin3, 
  const byte& _pin4
) {
  pin1 = _pin1;
  pin2 = _pin2;
  pin3 = _pin3;
  pin4 = _pin4;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  rpm = 12.0;
  intvl = 60000000.0 / _28BYJ48_SPR / rpm;
  nxt_idx = 0;
}

void _28BYJ48::setRPM(const float& _rpm) {
  rpm = _rpm;
  intvl = 60000000.0 / _28BYJ48_SPR / rpm;
}

void _28BYJ48::rotate(const int& steps) {
  int cnt = steps;
  int dir = steps < 0 ? -1 : 1;
  byte v1, v2, v3, v4;
  nxt_idx = steps < 0 ? 6 : 0;
  while (cnt) {
	v1 = seq[nxt_idx] & B1000 ? 1 : 0;
	v2 = seq[nxt_idx] & B0100 ? 1 : 0;
	v3 = seq[nxt_idx] & B0010 ? 1 : 0;
	v4 = seq[nxt_idx] & B0001 ? 1 : 0;
	digitalWrite(pin1, v1);
	digitalWrite(pin2, v2);
	digitalWrite(pin3, v3);
	digitalWrite(pin4, v4);
	cnt -= dir;
	nxt_idx = (nxt_idx + dir + 8) % 8;
	delayMicroseconds(intvl);
  }
}

void _28BYJ48::off() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}