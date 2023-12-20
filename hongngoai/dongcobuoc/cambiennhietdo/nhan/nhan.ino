#include <AccelStepper.h>
#include <IRremote.h>

IRrecv irrecv(9);
decode_results results;
AccelStepper stepper;

void setup() {
  stepper.setMaxSpeed(150);
  stepper.setAcceleration(100);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 256) {
      stepper.move((int)(90.0 * 1.8));
      stepper.runToPosition();
    } else {
      stepper.move((int)(-45.0 * 1.8));
      stepper.runToPosition();
    }
    Serial.println(results.value);
    irrecv.resume();
  }
  delay(300);
}