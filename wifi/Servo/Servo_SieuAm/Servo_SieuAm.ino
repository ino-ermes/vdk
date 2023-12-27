#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ICOFFEE";
const char* password = "xincamon";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);


#include <Servo.h>
Servo myservo;
void handleServo() {
  String angleString = server.arg("angle");
  int angle = angleString.toInt();
  Serial.println(angle);
  myservo.write(angle);
  server.send(200, "text/plain", "success");

}



const int trig = D1;
const int echo = D2;
float distance = 0.0;
void handleGetDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  distance = (float)pulseIn(echo, HIGH) / 2.0 / 29.412;
  server.send(200, "text/plain", String(distance));
}

void setup() {
  // Khởi động Serial để theo dõi thông tin debug
  Serial.begin(9600);
  Serial.println("Kết nối đến WiFi");

  // Kết nối WiFi
  WiFi.begin(ssid, password);
  Serial.println("Kết nối đến WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Đã kết nối thành công!");
  server.on("/distance", handleGetDistance);
  server.on("/servo", handleServo);

  // Khởi động máy chủ
  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  myservo.attach(D5,500, 2400);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  delay(1000);
}

void loop() {
  server.handleClient(); // Xử lý các yêu cầu từ client
}
