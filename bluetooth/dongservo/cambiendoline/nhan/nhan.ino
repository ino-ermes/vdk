#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial BTSerial(10, 11);
void setup() {
  Serial.begin(9600);
  myservo.attach(11, 500, 2500);
  BTSerial.begin(9600);
}

char value = '\0';
void loop() {
  if (BTSerial.available()) {
    value = BTSerial.read();
    Serial.write(value);
    Serial.write('\n');
    if (value == '0') {
      myservo.write(90);
      delay(500);
      myservo.write(0);
    } else if (value == '1') {
      myservo.write(180);
      delay(500);
      myservo.write(0);
    }
  }
  delay(500);
}