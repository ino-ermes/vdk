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
    
    if(gas > 100)
      BTSerial.write('0'); // thuan
    else
      BTSerial.write('1'); // nguoc
  }

}