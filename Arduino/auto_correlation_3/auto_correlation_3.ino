#define LEN 800

const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

float sample_freq;
byte rawData[LEN];
unsigned long timer;

int prePeak = 0;
int peakValue = 0;
int threshold = 125;   //set your own value based on your sensors
int noise = 5;

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
    rawData[i] = analogRead(A5)/2;
  }
  sample_freq = 1/(((float)(micros()-timer)/1000000) / LEN);
  Serial.println(sample_freq);
  
  //read sensor on pin A0
  
  
  int pre_i = 0;
  int count = 0;
  float sum = 0;
  for (int i = 0; i < LEN; i++) {
    int sensorValue = rawData[i];
    
    // check if it's higher than the current peak:
    peakValue = sensorValue > peakValue ? sensorValue : peakValue;
    if (sensorValue <= threshold - noise && peakValue > threshold + noise) {
      if (pre_i == 0) {
        pre_i = i;
        peakValue = 0;
        continue;
      }
      sum += sample_freq/(i-pre_i);
      peakValue = 0;
      pre_i = i;
      count++;
    }
  }
  
  Serial.println(sum/count);
  
  delay(1000);
}
