#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinX = A0;
const int pinY = A1;
const int pinBtn = 13;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
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

  if(BTSerial.available()) {
    BTSerial.read();

    if(x <= 100) {
      BTSerial.write('0');
    } else if(100 < x && x <= 250) {
      BTSerial.write('1');
    } else if(250 < x && x <= 400) {
      BTSerial.write('2');
    } else if(400 < x && x <= 600) {
      BTSerial.write('3');
    } else if(600 < x && x <= 750) {
      BTSerial.write('4');
    } else if(750 < x && x <= 900) {
      BTSerial.write('5');
    } else {
      BTSerial.write('6');
    }
  }
}