#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

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
    BTSerial.write('0');
  } else {
    BTSerial.write('1');
  }
  delay(100);
}