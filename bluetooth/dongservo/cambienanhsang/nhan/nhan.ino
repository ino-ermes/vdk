#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

#include <TinyStepper.h>
#define HALFSTEPS 4096
TinyStepper stepper(HALFSTEPS, 2, 3, 4, 5);


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

int angle = 90;
char value = '\0';
void loop() {
  if(BTSerial.available()) {
    value = BTSerial.read();
    if(value == '0') {
      angle = 90;
    }  else {
      angle = -45;
    }
    stepper.Move(angle);
  } else {
    BTSerial.write(".");
  }
  delay(500);
}