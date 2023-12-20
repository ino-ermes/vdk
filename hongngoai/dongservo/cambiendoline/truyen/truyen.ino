#include <IRremote.h>

IRsend irsend(3);

const int pinLine = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinLine, INPUT);
}

int line = LOW;
void loop() {
  line = digitalRead(pinLine);
  Serial.println(line);
  if (line == HIGH) {
    irsend.sendRC5(0x0, 8);
  } else {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}