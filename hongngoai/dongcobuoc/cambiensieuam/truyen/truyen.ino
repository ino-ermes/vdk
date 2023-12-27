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

uint8_t sCommand = 0x34;
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

  if (distance > 10) {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  }
  delay(1000);
}