#include <AccelStepper.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

AccelStepper stepper;

void setup() {
  stepper.setMaxSpeed(150);
  stepper.setAcceleration(100);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

char value = '\0';

void loop() {
  if (BTSerial.available()) {
    value = BTSerial.read();
    Serial.write(value);
    Serial.write('\n');
    if (value == '0') {
      stepper.move((int)(90.0 * 1.8));
      stepper.runToPosition();
    } else if (value == '1') {
      stepper.move((int)(-45.0 * 1.8));
      stepper.runToPosition();
    }
  }
}