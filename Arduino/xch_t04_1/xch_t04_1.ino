const int rPin = 11;
const int bPin = 10;
const int gPin = 9;

int rVal = 0;
int gVal = 85;
int bVal = 170;
int rDir = 1;
int gDir = 1;
int bDir = 1;

void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {  
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  
  if (rVal >= 255) { rDir = -1; } else if (rVal <= 0) { rDir = 1; }
  if (gVal >= 255) { gDir = -1; } else if (gVal <= 0) { gDir = 1; }
  if (bVal >= 255) { bDir = -1; } else if (bVal <= 0) { bDir = 1; }
  
  rVal = rVal + rDir;
  gVal = gVal + gDir;
  bVal = bVal + bDir;
  
  delay(10);
}
