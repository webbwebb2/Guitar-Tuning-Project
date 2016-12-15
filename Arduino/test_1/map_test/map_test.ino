void setup() {
  Serial.begin(9600);
  Serial.println(map(min(530, 500), 0, 500, 0, 255));
}

void loop() {
  // put your main code here, to run repeatedly:

}
