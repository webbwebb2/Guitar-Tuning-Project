#include <util.h>
#include <type.h>
#include <_math.h>

#define LEN 64

Complex a[LEN];
unsigned short i = 0;
unsigned int sample;
unsigned long start;
unsigned int max_j;
float max_val;
float sample_freq;

int interval_padding = 1112;

void setup() {
  Serial.begin(115200);
  start = micros();
}

void loop() {
  if(i == LEN) {
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
    Serial.print(max_j);
    Serial.print(" ");
    Serial.print(max_val);
    Serial.print(" ");
    Serial.print(sample_freq);
    Serial.print(" ");
    Serial.println(max_j * sample_freq / LEN);
    start = micros();
    //delay(1000);
  }
  a[i] = Complex((float)analogRead(A0), 0);
  //Serial.print((float)analogRead(A0));
  i++;
  delayMicroseconds(interval_padding);
  //Serial.println(micros() - start);
}
