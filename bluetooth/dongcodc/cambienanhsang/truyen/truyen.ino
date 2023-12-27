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
    if(light <= 600) {
      BTSerial.write('0');
    } else if(600 < light && light <= 650) {
      BTSerial.write('1');
    } else if(650 < light && light <= 700) {
      BTSerial.write('2');
    } else if(700 < light && light <= 750) {
      BTSerial.write('3');
    } else if(750 < light && light <= 800) {
      BTSerial.write('4');
    } else if(800 < light && light <= 850) {
      BTSerial.write('5');
    } else {
      BTSerial.write('6');
    }
  }
}