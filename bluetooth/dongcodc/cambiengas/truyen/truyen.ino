#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int pinGas = A0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

int gas = 0;
void loop() {

  if(BTSerial.available()) {
    BTSerial.read();

    gas = analogRead(pinGas);
    Serial.println(gas);
    
    if(gas <= 50) {
      BTSerial.write('0');
    } else if(50 < gas && gas <= 55) {
      BTSerial.write('1');
    } else if(55 < gas && gas <= 60) {
      BTSerial.write('2');
    } else if(60 < gas && gas <= 65) {
      BTSerial.write('3');
    } else if(65 < gas && gas <= 70) {
      BTSerial.write('4');
    } else if(70 < gas && gas <= 75) {
      BTSerial.write('5');
    } else {
      BTSerial.write('6');
    }
  }

}