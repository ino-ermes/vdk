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
    delay(50);
    Serial.print("Do am: ");
    Serial.println(humidity);
    delay(50);
    if(temperature > 27.0)
      BTSerial.write('0');
    else
      BTSerial.write('1');
  }
}