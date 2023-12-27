#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ICOFFEE";
const char* password = "xincamon";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);

#include <TinyStepper.h>
#define HALFSTEPS 4096
TinyStepper stepper(HALFSTEPS, D2, D5, D6, D7);
void handleStepper() {
  String angleString = server.arg("angle");
  int angle = angleString.toInt();
  Serial.println(angle);
  stepper.Move(angle, 3);
  server.send(200, "text/plain", "success");
}
const int trig = D0;
const int echo = D1;
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
  server.on("/stepper", handleStepper);

  // Khởi động máy chủ
  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: ");  // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  delay(1000);

}

void loop() {
  server.handleClient();  // Xử lý các yêu cầu từ client
}