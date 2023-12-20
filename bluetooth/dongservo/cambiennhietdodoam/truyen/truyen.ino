#include <DHT11.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

float temperature = 0;
int humidity = 0;

void loop() {
  temperature = dht11.readTemperature();
  humidity = dht11.readHumidity();

  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT && humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    if (humidity < 70) {
      BTSerial.write('0');
    } else {
      BTSerial.write('1');
    }
  }
  delay(1000);
}