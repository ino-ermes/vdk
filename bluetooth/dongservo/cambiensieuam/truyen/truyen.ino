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

    if(distance > 10) {
      BTSerial.write('0');
    } else {
      BTSerial.write('1');
    }
  }

}