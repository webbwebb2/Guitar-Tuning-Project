#include <util.h>
#include <type.h>
#include <_math.h>

Complex a[128];
unsigned short i = 0;
unsigned int sample;
unsigned long start;
unsigned int max_j;
float max_val;

void setup() {
  Serial.begin(115200);
}

void loop() {
  start = micros();
  if(i == 128) {
    i = 0;
    _fft_dit2(a, 128);
    
    Serial.println("start");
    for(int j=1;j<128;j++) {
      Serial.println(a[j].norm_sq());
    }
    Serial.println("end");
    
    // find max
    max_val = 0.0;
    max_j = -1;
    for(int j=1;j<64;j++) {
      max_val = (max_val>a[j].re) ? max_val : a[j].re;
      max_j = (max_val>a[j].re) ? max_j : j;
    }
    
    //Serial.print(max_j);
    //Serial.print(" ");
    //Serial.print(max_val);
    //Serial.print(" ");
    //Serial.println(max_j * 800 / 128);
    //delay(5000);
  }
  a[i] = Complex((float)analogRead(A0), 0);
  //Serial.print((float)analogRead(A0));
  i++;
  delayMicroseconds(1112);
  //Serial.println(micros() - start);
}
