#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinLine = 2;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

int line = 0;
void loop() {
  if(BTSerial.available()) {
    BTSerial.read();
    line = digitalRead(pinLine);
    Serial.println(line);
    if(line == HIGH) {
      BTSerial.write('0');
    } else {
      BTSerial.write('1');
    }
    // De o ngoai la line den, co vat can la line trang
  }
}