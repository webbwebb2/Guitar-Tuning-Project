#include <_28BYJ48.h>

#define PIN_S0 9
#define PIN_S1 8
#define PIN_S2 A0

int per_r = 2048;

_28BYJ48 motor(10, 11, 12, 13);
//Stepper motor(per_r, 10, 11, 12, 13);

void setup() {
  pinMode(PIN_S0, OUTPUT);
  pinMode(PIN_S1, OUTPUT);
  pinMode(PIN_S2, OUTPUT);
  
  motor.setRPM(16);
  
  digitalWrite(PIN_S0, HIGH);
  digitalWrite(PIN_S1, LOW);
  digitalWrite(PIN_S2, HIGH);
  
  motor.rotate(4075);
  motor.off();
  
//  digitalWrite(PIN_S0, LOW);
//  digitalWrite(PIN_S1, HIGH);
//  digitalWrite(PIN_S2, LOW
  delay(1000);
  motor.setRPM(10);
  motor.rotate(-4075);
  motor.off();
}

void loop() {
  
}
