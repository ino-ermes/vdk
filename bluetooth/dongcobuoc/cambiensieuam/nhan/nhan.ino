
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);


int motorPin1 = 2;
int motorPin2 = 3;
int motorPin3 = 4;
int motorPin4 = 5;
int light = 0;
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

int x, y, z, brake;
bool toggleStop = false;
int speed = 0;
String str;
int m;
float deg;
bool inve = false;


void loop() {
  if (BTSerial.available()) {
    char v = BTSerial.read();
    Serial.write(v);
    Serial.write("\n");
    if (v == '0') inve = false;
    if (v == '1') inve = true;
    Serial.println(inve);

  }
  if (!inve) {
    m = (int)((90 * 512.0) / 360.0);
    brake = 15;
    Serial.println("normal");
    for (int i = 0; i < m; ++i) {
      normal();
    }
  } else {
    m = (int)((45 * 512.0) / 360.0);
    brake = 15;
    Serial.println("inv");
    for (int i = 0; i < m; ++i) {
      normal();
    }
  }
  delay(1000);
}


void A() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(brake);
}
void AA() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(brake);
}
void BB() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(brake);
}
void B() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(brake);
}

void normal() {
  A();
  AA();
  B();
  BB();
}
void inverse() {
  BB();
  B();
  AA();
  A();
}