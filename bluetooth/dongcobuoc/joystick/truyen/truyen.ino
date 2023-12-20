#include <IRremote.h>

IRsend irsend(3);

const int pinX = A0;
const int pinY = A1;
const int pinBtn = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinBtn, INPUT_PULLUP);
}

int x = 0;
int y = 0;
bool btn = false;
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
    irsend.sendRC5(0x0, 8);
  } else if(x < 400) {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}