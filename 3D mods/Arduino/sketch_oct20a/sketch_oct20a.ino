#include <util.h>
#include <type.h>
#include <_math.h>



Complex a[] = {
  Complex(1, 2),Complex(3, 4),Complex(5, 6),Complex(7, 8),Complex(9, 10),Complex(11, 12),Complex(13, 14),Complex(15, 16)
};

/*
Complex a[] = {
  Complex(0, 0),Complex(0, 0),Complex(0, 0),Complex(0, 0),Complex(0, 0),Complex(0, 0),Complex(0, 0),Complex(0, 0)
};
*/

long ts = 0;
long te = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Complex* b = dft(a, 8);
  _fft_dit2(a, 8);
  for(int i=0;i<8;i++) {
    Serial.print(b[i].toString());
    Serial.println(a[i].toString());
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  ts = micros();
  _fft_dit2(a, 32);
  te = micros();
  Serial.print("fft: ");
  Serial.println(te - ts);
  delay(1000);
  */
}
