#include <SoftwareSerial.h>

int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (i == 100)
    i = 0;
  else
    i++;
  Serial.println(i);
  delay(500);
}
