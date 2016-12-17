#include <FreqCounter.h>

void setup() {
  Serial.begin(115200);                    // connect to the serial port
  Serial.println("Frequency Counter");
}

long int frq;
void loop() {

 FreqCounter::f_comp= 8;             // Set compensation to 12
 FreqCounter::start(100);            // Start counting with gatetime of 100ms
 while (FreqCounter::f_ready == 0)         // wait until counter ready
 
 frq=FreqCounter::f_freq;            // read result
 Serial.println(frq);                // print result
 delay(20);
}
