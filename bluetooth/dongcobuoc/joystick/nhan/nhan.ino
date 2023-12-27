#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

#include <TinyStepper.h>
#define HALFSTEPS 4096
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
TinyStepper stepper(HALFSTEPS, IN1, IN2, IN3, IN4);


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

int angle = 90;
char value = '\0';
void loop() {
  if(BTSerial.available()) {
    value = BTSerial.read();
    if(value == '0') {
      angle = 90;
    }  else if(value == '1') {
      angle = -45;
    } else {
      angle = 0;
    }
    stepper.Move(angle);
  } else {
    BTSerial.write(".");
  }
  delay(500);
}