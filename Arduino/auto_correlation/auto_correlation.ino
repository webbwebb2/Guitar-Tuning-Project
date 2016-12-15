#define LEN 256

// Define various ADC prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

float sample_freq;

int rawData[LEN];
int i,k;
long sum, sum_old;
int thresh = 0;
float freq_per = 0;
byte pd_state = 0;
int count = 0;
unsigned long start;
  
void setup() {
  Serial.begin(115200);
  ADCSRA &= ~PS_128;
  ADCSRA |=  PS_32;
  start = micros();
}

void loop() {
  if (count == LEN) {
    sample_freq = 1000000 / (float)(micros() - start) * LEN;
    count = 0;
    sum = 0;
    pd_state = 0;
    int period = 0;
    // Autocorrelation
    Serial.println("start");
    for(i=0; i < LEN; i++)
    {
      sum_old = sum;
      sum = 0;
      for(k=0; k < LEN-i; k++) {
        sum += (rawData[k]-250)*(rawData[k+i]-250)/(LEN-i);
      }
      
      Serial.println(sum);
      
      // Peak Detect State Machine
      if (pd_state == 2 && (sum-sum_old) <=0) 
      {
        period = i;
        pd_state = 3;
      }
      if (pd_state == 1 && (sum > thresh) && (sum-sum_old) > 0) pd_state = 2;
      if (!i) {
        thresh = sum * 0.5;
        pd_state = 1;
      }
    }
    Serial.println("end");
    
    // Frequency identified in Hz
    freq_per = sample_freq/period;
    //Serial.println(sample_freq);
    //Serial.println(freq_per);
    start = micros();
  }
  
  rawData[count] = analogRead(A5);
  count++;
} 
