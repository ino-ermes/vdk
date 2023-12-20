#include <IRremote.h>

IRsend irsend(3);

const int pinGas = A0;

void setup() {
  Serial.begin(9600);
}

int gas = 0;
void loop() {
  gas = analogRead(pinGas);
  Serial.println(gas);
  if (gas < 100) {
    irsend.sendRC5(0x0, 8);
  } else {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}