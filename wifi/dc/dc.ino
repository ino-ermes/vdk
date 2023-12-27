#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// const char* ssid = "Redmi Note 9S";
// const char* password = "qazwsx123";
const char* ssid = "ICOFFEE";
const char* password = "xincamon";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);

#define IN1 D6 // D6 (chân số) 
#define IN2 D5 // D5 (chân số)
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

void handleDC() {
  String directionS = server.arg("direction");
  String speedS = server.arg("speed");

  int direction = directionS.toInt();
  int speed = speedS.toInt();
  Serial.println(direction);
  Serial.println(speed);

  if(direction == 0) {
    Lui(speed);
  } else if(direction == 1) {
    Tien(speed);
  }

  server.send(200, "text/plain", "success");
}

void setup() {
  // Khởi động Serial để theo dõi thông tin debug
  Serial.begin(9600);
  Serial.println("Kế2222t nối đến WiFi");

  // Kết nối WiFi
  WiFi.begin(ssid, password);
  Serial.println("Kết nối đến WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Đã kết nối thành công!");
  server.on("/dc-motor", handleDC);

  // Khởi động máy chủ
  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: ");  // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  delay(1000);
}

void loop() {
  server.handleClient();  // Xử lý các yêu cầu từ client
}
