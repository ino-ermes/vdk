#include <IRremote.h>
#define IR_RECEIVE_PIN 2


#include <Servo.h>
Servo myservo;
const int pinServo = 9;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  myServo.attach(pinServo, 500, 2500);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);

    if(IrReceiver.decodedIRData.command == 0x34) {
      myservo.write(90);
      delay(500);
      myservo.write(0);
      delay(250);
    } else {
      myservo.write(45);
      delay(500);
      myservo.write(0);
      delay(250);
    }
    IrReceiver.resume();
  }
}