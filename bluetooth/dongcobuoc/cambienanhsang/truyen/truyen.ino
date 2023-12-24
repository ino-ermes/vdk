#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinLight = A0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

int light = 0;
void loop() {
  if(BTSerial.available()) {
    BTSerial.read();
    light = analogRead(pinLight);
    Serial.println(light);
    if(light > 800) {
      BTSerial.write('0');
    } else {
      BTSerial.write('1');
    }
  }
}