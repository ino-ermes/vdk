#include <IRremote.h>

IRsend irsend(3);

const int pinLight = A0;

void setup() {
  Serial.begin(9600);
}

int light = 0;
void loop() {
  light = analogRead(pinLight);
  Serial.println(light);
  if (light < 100) {
    irsend.sendRC5(0x0, 8);
  } else {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}