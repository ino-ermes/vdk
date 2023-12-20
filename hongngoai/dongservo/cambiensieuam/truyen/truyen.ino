#include <IRremote.h>

IRsend irsend(3);

const int trig = 8;  // chân trig của HC-SR04
const int echo = 7;  // chân echo của HC-SR04

void setup() {
  pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
  Serial.begin(9600);
}

unsigned long duration;  // biến đo thời gian
int distance;            // biến lưu khoảng cách

void loop() {

  /* Phát xung từ chân trig */
  digitalWrite(trig, 0);  // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig, 1);  // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trig, 0);  // tắt chân trig

  /* Tính toán thời gian */
  duration = pulseIn(echo, HIGH);                  // Đo độ rộng xung HIGH ở chân echo.
  distance = int((float)duration / 2.0 / 29.412); // Tính khoảng cách đến vật.

  /* In kết quả ra Serial Monitor */
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10) {
    irsend.sendRC5(0x0, 8);
  } else {
    irsend.sendRC5(0x1, 8);
  }
  delay(100);
}