const int senPin = A0;
const float bTemp = 18.0;

void setup() {
  // set up pins
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  digitalWrite(7, 0);
  pinMode(6, OUTPUT);
  digitalWrite(6, 0);
  pinMode(3, OUTPUT);
  digitalWrite(3, 0);
}

void loop() {
  int senVal = analogRead(senPin);
  Serial.print("Sensor Value: ");
  Serial.print(senVal);
  
  // convert the ACD reading to voltage
  float voltage = (senVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degree C: ");
  
  // convert the voltage to temperature in degrees
  float temp = (voltage - .5) * 100;
  Serial.println(temp);
  
  if (temp < bTemp) {
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    digitalWrite(3, 0);
  } else if ( temp >= bTemp + 2 &&
      temp < bTemp + 4) {
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    digitalWrite(3, 1);
  } else if ( temp >= bTemp + 4 &&
      temp < bTemp + 6) {
    digitalWrite(7, 0);
    digitalWrite(6, 1);
    digitalWrite(3, 1);
  } else if ( temp >= bTemp + 6) {
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(3, 1);
  }
  
  delay(1);
}
