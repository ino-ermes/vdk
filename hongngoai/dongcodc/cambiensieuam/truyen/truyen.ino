#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

const int trig = 7;
const int echo = 6;
unsigned long duration;
int distance;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

uint8_t sCommand = 0x00;
uint8_t sRepeats = 0;

void loop() {

  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);

  duration = pulseIn(echo, HIGH);
  distance = int((float)duration / 2.0 / 29.412);

  Serial.println(distance);

  if(distance <= 5) {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  } else if(5 < distance && distance <= 8) {
    IrSender.sendNEC(0x00, sCommand + 0x12, sRepeats);
  } else if(8 < distance && distance <= 11) {
    IrSender.sendNEC(0x00, sCommand + 0x13, sRepeats);
  } else if(11 < distance && distance <= 14) {
    IrSender.sendNEC(0x00, sCommand + 0x14, sRepeats);
  } else if(14 < distance && distance <= 17) {
    IrSender.sendNEC(0x00, sCommand + 0x15, sRepeats);
  } else if(17 < distance && distance <= 20) {
    IrSender.sendNEC(0x00, sCommand + 0x16, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x17, sRepeats);
  }
  delay(1000);
}