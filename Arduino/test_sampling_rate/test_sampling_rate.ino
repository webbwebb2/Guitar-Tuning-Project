
unsigned long start;
unsigned short i = 0;
unsigned int delay_us = 1122;

void setup() {
  Serial.begin(9600);
}

void loop() {
  start = micros();
  if(i == 128) {
    i = 0;
  }
  analogRead(A0);
  i++;
  delayMicroseconds(delay_us);
  Serial.println(micros() - start);
}
