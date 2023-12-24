#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);


#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(2);
}

int angle = 90;
char value = '\0';
void loop() {
  if(BTSerial.available()) {
    value = BTSerial.read();
    if(value == '0') {
      angle = 90;
    }  else if (value = '2') {
      angle = 45;
    } else {
      angle = 0;
    }
    myservo.write(angle);
    delay(500);
    myservo.write(0);
  } else {
    BTSerial.write(".");
  }
  delay(500);
}