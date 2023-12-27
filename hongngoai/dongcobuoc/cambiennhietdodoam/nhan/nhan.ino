#include <IRremote.h>
#define IR_RECEIVE_PIN 2


#include <TinyStepper.h>
#define HALFSTEPS 4096
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
TinyStepper stepper(HALFSTEPS, IN1, IN2, IN3, IN4);

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);

    if(IrReceiver.decodedIRData.command == 0x34) {
      stepper.Move(90, 3);
    } else {
      stepper.Move(-45, 3);
    }
    IrReceiver.resume();
  }
}