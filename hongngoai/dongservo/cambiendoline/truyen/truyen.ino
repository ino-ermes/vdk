#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

const int pinLine = 8;
int line = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);
}

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {
  line = digitalRead(pinLine);
  Serial.println(line);
  if(line == HIGH) {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  }
  delay(1000);
}