#include <_28BYJ48.h>

#define PIN_S0 9
#define PIN_S1 8
#define PIN_S2 A0
#define PIN_CH4 13
#define PIN_CH6 12
#define PIN_CH3 11
#define PIN_CH5 10
#define PIN_COM 8

_28BYJ48 motor(10, 11, 12, 13);

void setup() {
  motor.setRPM(21
  );
  pinMode(PIN_S0, OUTPUT);
  pinMode(PIN_S1, OUTPUT);
  pinMode(PIN_S2, OUTPUT);

  // select 4
  digitalWrite(PIN_S0, HIGH);
  digitalWrite(PIN_S1, LOW);
  digitalWrite(PIN_S2, LOW);
  motor.rotate(4075);
  motor.off();
  
  digitalWrite(PIN_S0, LOW);
  digitalWrite(PIN_S1, HIGH);
  digitalWrite(PIN_S2, LOW);
  motor.rotate(4075);
  motor.off();
  
  digitalWrite(PIN_S0, LOW);
  digitalWrite(PIN_S1, LOW);
  digitalWrite(PIN_S2, LOW);
}

void loop() {
}

