#include <IRremote.h>

IRsend irsend(3);

const int pinTemp = A0;

void setup() {
  Serial.begin(9600);
}

int value = 0;
float temp = 0;
void loop() {
  value = analogRead(pinTemp);
  temp = (double)value * 5.0 / 10.24;
  Serial.println(temp);
  if (temp < 30) {
    irsend.sendRC5(0x0, 8);
  } else {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}