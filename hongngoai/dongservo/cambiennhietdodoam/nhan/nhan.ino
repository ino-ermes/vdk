#include <IRremote.h>
#include <Servo.h>

Servo myservo;
IRrecv irrecv(9);
decode_results results;

void setup() {
  Serial.begin(9600);
  myservo.attach(11, 500, 2500);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 256) {
      myservo.write(90);
      delay(500);
      myservo.write(0);
    } else {
      myservo.write(180);
      delay(500);
      myservo.write(0);
    }
    Serial.println(results.value);
    irrecv.resume();
  }
  delay(500);
}