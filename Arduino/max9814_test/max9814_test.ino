unsigned long start;
unsigned int sample;

void setup() 
{
   Serial.begin(9600);
}
 
 
void loop() 
{
   start= micros();  // Start of sample window
   sample = analogRead(0);
   Serial.println(micros() - start);
}
