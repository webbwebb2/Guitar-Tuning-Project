const int rPin = 11;
const int bPin = 10;
const int gPin = 9;

int rVal = 0;
int gVal = 0;
int bVal = 0;
int rDir = 0;
int gDir = 0;
int bDir = 0;

int i = 0;

void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {  
  switch (i / 255) {
    case 0:
      rDir = 1; gDir = 0; bDir = 0; break;
    case 1:
      rDir = -1; gDir = 0; bDir = 0; break;
    case 2:
      rDir = 0; gDir = 1; bDir = 0; break;
    case 3:
      rDir = 0; gDir = -1; bDir = 0; break;
    case 4:
      rDir = 0; gDir = 0; bDir = 1; break;
    case 5:
      rDir = 0; gDir = 0; bDir = -1; break;
    default:
      rDir = 0; gDir = 0; bDir = 0;
  }
  
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  
  rVal = rVal + rDir;
  gVal = gVal + gDir;
  bVal = bVal + bDir;
  
  i++;
  
  if (i == 255 * 6) {
    i = 0;
  }
  
  delay(10);
}
