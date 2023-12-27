#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);


#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  myServo.attach(2, 500, 2500);
}

int angle = 90;
char value = '\0';
void loop() {
  if(BTSerial.available()) {
    value = BTSerial.read();
    if(value == '0') {
      angle = 90;
    }  else {
      angle = 45;
    }
    myservo.write(angle);
    delay(500);
    myservo.write(0);
  } else {
    BTSerial.write(".");
  }
  delay(500);
}