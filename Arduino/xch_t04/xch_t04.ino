const int rPin = 11;
const int bPin = 10;
const int gPin = 9;

const int rSenPin = A0;
const int gSenPin = A1;
const int bSenPin = A2;

int rVal = 0;
int gVal = 0;
int bVal = 0;

int rSenVal = 0;
int gSenVal = 0;
int bSenVal = 0;

int wait = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  rSenVal = analogRead(rSenPin);
  delay(5);
  gSenVal = analogRead(gSenPin);
  delay(5);
  bSenVal = analogRead(bSenPin);
  
  if (wait == 100) {
    Serial.print("Raw\t R: ");
    Serial.print(rSenVal);
    Serial.print("\t G: ");
    Serial.print(gSenVal);
    Serial.print("\t B: ");
    Serial.println(bSenVal);
  }
  
  rVal = rSenVal / 4;
  gVal = gSenVal / 4;
  bVal = bSenVal / 4;
  
  if (wait == 100) {
    Serial.print("Mapped\t R: ");
    Serial.print(rVal);
    Serial.print("\t G: ");
    Serial.print(gVal);
    Serial.print("\t B: ");
    Serial.println(bVal);
    wait = 0;
  }
  
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  
  wait++;
}
