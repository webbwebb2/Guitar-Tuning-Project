#include <util.h>
#include <type.h>
#include <_math.h>

unsigned int a[512];
unsigned long start;

float sample_freq = 8620;
int i,k,j;
long sum, sum_old;
int thresh = 0;
float freq_per = 0;
byte pd_state = 0;

void setup() {
  Serial.begin(9600);
  sum = 0;
  pd_state = 0;
  int period = 0;
}

void loop() {
  start = micros();
  if (i == 512) {
    i = 0;
    for(j=0; j < 128; j++) {
      sum_old = sum;
      sum = 0;
      for(k=0; k < len-j; k++) 
        sum += rawData[k] * rawData[k+j]/256;
    }
    
  } else {
  
    // read from A0
    a[i] = analogRead(A0);
    i++;
    //delayMicroseconds(45);
    Serial.println(1000000 / (micros() - start));
  }
}
