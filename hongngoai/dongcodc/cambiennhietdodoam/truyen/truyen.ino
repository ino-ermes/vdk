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

uint8_t sCommand = 0x00;
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

  if(humidity <= 50) {
    IrSender.sendNEC(0x00, sCommand + 0x11, sRepeats);
  } else if(50 < humidity && humidity <= 55) {
    IrSender.sendNEC(0x00, sCommand + 0x12, sRepeats);
  } else if(55 < humidity && humidity <= 60) {
    IrSender.sendNEC(0x00, sCommand + 0x13, sRepeats);
  } else if(60 < humidity && humidity <= 65) {
    IrSender.sendNEC(0x00, sCommand + 0x14, sRepeats);
  } else if(65 < humidity && humidity <= 70) {
    IrSender.sendNEC(0x00, sCommand + 0x15, sRepeats);
  } else if(70 < humidity && humidity <= 75) {
    IrSender.sendNEC(0x00, sCommand + 0x16, sRepeats);
  } else {
    IrSender.sendNEC(0x00, sCommand + 0x17, sRepeats);
  }
  delay(1000);
}