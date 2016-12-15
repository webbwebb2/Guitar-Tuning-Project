#include <util.h>
#include <type.h>
#include <_math.h>

#define LEN 2048
#define SERIAL SerialUSB

Complex a[LEN];
unsigned short i = 0;
unsigned int sample;
unsigned long start;
unsigned int max_j;
float max_val;
float sample_freq;

int interval_padding = 1000;

void setup() {
  SERIAL.begin(115200);
}

void loop() {
  start = micros();
  for (i = 0; i < LEN; i++) {
    a[i] = Complex((float)analogRead(A5), 0);
    delayMicroseconds(interval_padding);
  }
  sample_freq = 1000000 / (float)(micros() - start) * LEN;
  i = 0;
  _fft_dit2(a, LEN);
    /*
    for(int j=0;j<LEN;j++) {
      Serial.println(a[j].toString());
    }
    */
    // find max
  max_val = 0.0;
  max_j = -1;
  for(int j=1;j<LEN/2;j++) {
    max_val = (max_val>a[j].norm_sq()) ? max_val : a[j].norm_sq();
    max_j = (max_val>a[j].norm_sq()) ? max_j : j;
  }
  SERIAL.print(max_j);
  SERIAL.print(" ");
  SERIAL.print(max_val);
  SERIAL.print(" ");
  SERIAL.print(sample_freq);
  SERIAL.print(" ");
  SERIAL.println(max_j * sample_freq / LEN);
}
