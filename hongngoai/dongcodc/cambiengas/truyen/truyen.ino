#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

const int pinGas = A0;
int gas = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);
}

uint8_t sCommand = 0x00;
uint8_t sRepeats = 0;

void loop() {
  gas = analogRead(pinGas);
  Serial.println(gas);
  if(gas <= 50) {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  } else if(50 < gas && gas <= 55) {
    IrSender.sendNEC(0x00, sCommand + 0x12, sRepeats);
  } else if(55 < gas && gas <= 60) {
    IrSender.sendNEC(0x00, sCommand + 0x13, sRepeats);
  } else if(60 < gas && gas <= 65) {
    IrSender.sendNEC(0x00, sCommand + 0x14, sRepeats);
  } else if(65 < gas && gas <= 70) {
    IrSender.sendNEC(0x00, sCommand + 0x15, sRepeats);
  } else if(70 < gas && gas <= 75) {
    IrSender.sendNEC(0x00, sCommand + 0x16, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x17, sRepeats);
  }
  delay(1000);
}