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

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {
  light = analogRead(pinLight);
  Serial.println(light);
  if(light > 900) {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  }
  delay(1000);
}