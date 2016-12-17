#include "dstruct.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  TrotArray arr(4);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(6);
  arr.push_back(7);
  arr.push_back(8);
  arr.push_back(9);
  arr[1] = 10;
  arr.push_back(11);
  Serial.println(arr[0]);
  Serial.println(arr[1]);
  Serial.println(arr[2]);
  Serial.println(arr[3]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
