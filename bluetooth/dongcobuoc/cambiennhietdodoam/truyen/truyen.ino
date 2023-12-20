#include <DHT11.h>
#include <IRremote.h>

IRsend irsend(3);

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
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
      irsend.sendRC5(0x0, 8);
    } else {
      irsend.sendRC5(0x1, 8);
    }
  }
  delay(1000);
}