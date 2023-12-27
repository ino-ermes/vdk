#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

const int pinLight = A0;
int light = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);
}

uint8_t sCommand = 0x00;
uint8_t sRepeats = 0;

void loop() {
  light = analogRead(pinLight);
  Serial.println(light);
  if(light <= 600) {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  } else if(600 < light && light <= 650) {
    IrSender.sendNEC(0x00, sCommand + 0x12, sRepeats);
  } else if(650 < light && light <= 700) {
    IrSender.sendNEC(0x00, sCommand + 0x13, sRepeats);
  } else if(700 < light && light <= 750) {
    IrSender.sendNEC(0x00, sCommand + 0x14, sRepeats);
  } else if(750 < light && light <= 800) {
    IrSender.sendNEC(0x00, sCommand + 0x15, sRepeats);
  } else if(800 < light && light <= 850) {
    IrSender.sendNEC(0x00, sCommand + 0x16, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x17, sRepeats);
  }
  delay(1000);
}