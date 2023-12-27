#include <DHT.h>
#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  dht.begin();
}

float temperature = 0.0;
float humidity = 0.0;
float tmp = 0.0;

void loop() {

  if(BTSerial.available()) {
    BTSerial.read();

    tmp = dht.readTemperature();
    if(!isnan(tmp))
      temperature = tmp;
    delay(50);
    tmp = dht.readHumidity();
    if(!isnan(tmp))
      humidity = tmp;

    Serial.print("Nhiet do: ");
    Serial.println(temperature);
    Serial.print("Do am: ");
    Serial.println(humidity);

    if(humidity <= 50) {
      BTSerial.write('0');
    } else if(50 < humidity && humidity <= 55) {
      BTSerial.write('1');
    } else if(55 < humidity && humidity <= 60) {
      BTSerial.write('2');
    } else if(60 < humidity && humidity <= 65) {
      BTSerial.write('3');
    } else if(65 < humidity && humidity <= 70) {
      BTSerial.write('4');
    } else if(70 < humidity && humidity <= 75) {
      BTSerial.write('5');
    } else {
      BTSerial.write('6');
    }
  }
}