int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  
  if (switchState == 0) {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  } else {
    digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    
    delay(250);   // wait for 1/4 sec
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    delay(250);
  }
}
