#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

const int pinX = A0;
const int pinY = A1;
const int pinBtn = 8;
int x = 0;
int y = 0;
bool btn = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);

  pinMode(pinBtn, INPUT_PULLUP);
}

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {

  x = analogRead(pinX);
  y = analogRead(pinY);
  btn = digitalRead(pinBtn) == LOW;
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | ");
  Serial.print("y: ");
  Serial.print(y);
  Serial.print(" | ");
  Serial.print("btn: ");
  Serial.println(btn);


  if (x > 600) {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  }
  delay(1000);
}