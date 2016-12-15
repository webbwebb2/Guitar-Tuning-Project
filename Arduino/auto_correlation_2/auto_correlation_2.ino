#define LEN 256

const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

float sample_freq;
int rawData[LEN];
unsigned long timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ADCSRA &= ~PS_128;
  ADCSRA |=  PS_64;
}

void loop() {
  // put your main code here, to run repeatedly:
  timer = micros();
  for (int i = 0; i < LEN; i++) {
    rawData[i] = analogRead(A5);
  }
  sample_freq = 1/(((float)(micros()-timer)/1000000) / LEN);
  Serial.println(sample_freq);
}
