#include <IRremote.h>
#define IR_RECEIVE_PIN 2

// OUT1 và OUT2 nối với động cơ DC 
// 12V L298N với 5V Arduino , GND L289N nối với GND Arduino
#define IN1 6 // D6 (chân số) 
#define IN2 5 // D5 (chân số)
#define MAX_SPEED 255
#define MIN_SPEED 0                

void Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);  
  digitalWrite(IN1, LOW);                      
  analogWrite(IN2, speed);
}
void Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN1, speed); 
  digitalWrite(IN2, LOW);
}
void NhanhDan(){
  digitalWrite(IN2 , LOW);
  for (int i = 100 ; i <= 255 ; i++){
    analogWrite(IN1 , i);
    delay(50);
  }
}
void ChamDan(){
  digitalWrite(IN2 , LOW);
  for (int i = 255; i >= 100 ; i--){
    analogWrite(IN1 , i);
    delay(50);
  }
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  if(IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    switch (IrReceiver.decodedIRData.command) {
      case 0x11:
        Lui(255);
        break;
      case 0x12:
        Lui(177);
        break;
      case 0x13:
        Lui(100);
        break;
      case 0x14:
        Dung();
        break;
      case 0x15:
        Tien(100);
        break;
      case 0x16:
        Tien(177);
        break;
      case 0x17:
        Tien(255);
        break;
    }
    IrReceiver.resume();
  }
}