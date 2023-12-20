#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinLight = A0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

}

int light = 0;
void loop() {
  light = analogRead(pinLight);
  Serial.println(light);
  if (light < 100) {
    BTSerial.write('0');
  } else {
    BTSerial.write('1');
  }
  delay(100);
}