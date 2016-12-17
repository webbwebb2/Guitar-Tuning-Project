#include <util.h>
#include <type.h>
#include <_math.h>

#define DEBUG true
#define DFT_LEN 64
#define AMP_PIN A0

Complex data[DFT_LEN];
unsigned short i = 0;
unsigned long timer;
int max_ch;          // the channel of the max energy
float max_nrg;       // max energy 
float frq;           // real sampling frequency
int _delay = 1112;   // sampling delay (in us)

void setup() {
  Serial.begin(115200);
  timer = micros();
}

void loop() {
  // do fft and calc base frquency if samples are enough
  if (i == DFT_LEN) {
    // calc sampling frquency
    frq = 1000000.0 / (micros() - timer) * DFT_LEN;
    _fft_dit2(data, DFT_LEN);
    max_nrg = 0.0;
    max_ch  = 0;
    for (int ch = 1; ch < DFT_LEN / 2; ch++) {
      float nrg = data[ch].norm_sq();
      max_nrg = (max_nrg > nrg) ? max_nrg : nrg;
      max_ch  = (max_nrg > nrg) ? max_ch : ch;
    }
    
    // optimize sampling frequency by adjusing sampling delay
    float pos = max_ch / DFT_LEN.0;
    if (pos < 0.5 || pos > 0.9)
      _delay = 1112;
    
    // output info if DEBUG is on
    if (DEBUG) {
      Serial.print(max_ch);
      Serial.print(" ");
      Serial.print(max_nrg);
      Serial.print(" ");
      Serial.print(frq);
      Serial.print(" ");
      Serial.println(max_ch * frq / DFT_LEN);
    }
    
    // reset for the next sampling routine
    i = 0;
    timer = micros();
  }
  
  // sampling routine
  data[i++] = Complex((float)analogRead(AMP_PIN), 0);
  delayMicroseconds(_delay);
}
