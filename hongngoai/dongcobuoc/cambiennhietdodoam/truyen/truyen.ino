#include <IRremote.h>

#define DISABLE_CODE_FOR_RECEIVER  // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#define IR_SEND_PIN 3

#include <DHT.h>
const int pinDHT = 9;
DHT dht(pinDHT, DHT11);
float temperature = 0.0;
float humidity = 0.0;
float tmp = 0.0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  IrSender.begin(IR_SEND_PIN);

  dht.begin();
}

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {
  tmp = dht.readTemperature();
  if (!isnan(tmp))
    temperature = tmp;
  tmp = dht.readHumidity();
  if (!isnan(tmp))
    humidity = tmp;

  Serial.print("Nhiet do: ");
  Serial.println(temperature);
  Serial.print("Do am: ");
  Serial.println(humidity);

  if (humidity > 85) {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  }
  delay(1000);
}