#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int trig = 7;
const int echo = 6;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

unsigned long duration;
int distance;

void loop() {
  if(BTSerial.available()) {
    BTSerial.read();

    digitalWrite(trig, 0);
    delayMicroseconds(2);
    digitalWrite(trig, 1);
    delayMicroseconds(5);
    digitalWrite(trig, 0);

    duration = pulseIn(echo, HIGH);
    distance = int((float)duration / 2.0 / 29.412);

    Serial.print(distance);
    Serial.println("cm");

    if(distance <= 5) {
      BTSerial.write('0');
    } else if(5 < distance && distance <= 8) {
      BTSerial.write('1');
    } else if(8 < distance && distance <= 11) {
      BTSerial.write('2');
    } else if(11 < distance && distance <= 14) {
      BTSerial.write('3');
    } else if(14 < distance && distance <= 17) {
      BTSerial.write('4');
    } else if(17 < distance && distance <= 20) {
      BTSerial.write('5');
    } else {
      BTSerial.write('6');
    }
  }

}