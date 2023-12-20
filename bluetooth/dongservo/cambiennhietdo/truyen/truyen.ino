#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinTemp = A0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

int value = 0;
float temp = 0;
void loop() {
  value = analogRead(pinTemp);
  temp = (double)value * 5.0 / 10.24;
  Serial.println(temp);
  if (temp < 30) {
    BTSerial.write('0');
  } else {
    BTSerial.write('1');
  }
  delay(100);
}