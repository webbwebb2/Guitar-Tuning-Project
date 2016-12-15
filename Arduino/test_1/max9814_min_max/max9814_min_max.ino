int _max = 0;
int _min = 1023;
int input = 0;
int count = 0;
long sum = 0;

const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

void setup() {
  Serial.begin(115200);
  ADCSRA &= ~PS_128;
  ADCSRA |=  PS_16;
}

void loop() {
  // put your main code here, to run repeatedly:
  input = analogRead(A5);
  if (_max < input)
    _max = input;
  if (_min > input)
    _min = input;
  sum += input;
  count++;
  if (count == 5000) {
    Serial.print("max: ");
    Serial.print(_max);
    Serial.print(" min: ");
    Serial.print(_min);
    Serial.print(" mean: ");
    Serial.println(sum / 5000);
    _max = 0;
    _min = 1023;
    count = 0;
    sum = 0;
  }
}
