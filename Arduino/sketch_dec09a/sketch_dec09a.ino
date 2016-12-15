void setup() {
  SerialUSB.begin(115200);
  SerialUSB.print("hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialUSB.begin(115200);
  SerialUSB.println("hello");
}
