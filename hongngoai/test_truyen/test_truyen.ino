#include <IRremote.h>

IRsend irsend(3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  irsend.sendRC5(0x0, 8);
  delay(500);
  irsend.sendRC5(0x1, 8);
  delay(500);
}