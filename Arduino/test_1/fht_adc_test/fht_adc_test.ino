   1 /*
   2 fht_adc.pde
   3 guest openmusiclabs.com 9.5.12
   4 example sketch for testing the fht library.
   5 it takes in data on ADC0 (Analog0) and processes them
   6 with the fht. the data is sent out over the serial
   7 port at 115.2kb.  there is a pure data patch for
   8 visualizing the data.
   9 */
  10 
  11 #define LOG_OUT 1 // use the log output function
  12 #define FHT_N 256 // set to 256 point fht
  13 
  14 #include <FHT.h> // include the library
  15 
  16 void setup() {
  17   Serial.begin(115200); // use the serial port
  18   TIMSK0 = 0; // turn off timer0 for lower jitter
  19   ADCSRA = 0xe5; // set the adc to free running mode
  20   ADMUX = 0x40; // use adc0
  21   DIDR0 = 0x01; // turn off the digital input for adc0
  22 }
  23 
  24 void loop() {
  25   while(1) { // reduces jitter
  26     cli();  // UDRE interrupt slows this way down on arduino1.0
  27     for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
  28       while(!(ADCSRA & 0x10)); // wait for adc to be ready
  29       ADCSRA = 0xf5; // restart adc
  30       byte m = ADCL; // fetch adc data
  31       byte j = ADCH;
  32       int k = (j << 8) | m; // form into an int
  33       k -= 0x0200; // form into a signed int
  34       k <<= 6; // form into a 16b signed int
  35       fht_input[i] = k; // put real data into bins
  36     }
  37     fht_window(); // window the data for better frequency response
  38     fht_reorder(); // reorder the data before doing the fht
  39     fht_run(); // process the data in the fht
  40     fht_mag_log(); // take the output of the fht
  41     sei();
  42     Serial.write(255); // send a start byte
  43     Serial.write(fht_log_out, FHT_N/2); // send out the data
  44   }
  45 }
