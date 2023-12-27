#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ICOFFEE";
const char* password = "xincamon";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);

#include <TinyStepper.h>
#define HALFSTEPS 4096
TinyStepper stepper(HALFSTEPS, D1, D2, D3, D4);
void handleStepper() {
  String angleString = server.arg("angle");
  int angle = angleString.toInt();
  stepper.Move(angle);
  server.send(200, "text/plain", "success");
}

const int lightPin = A0;
void handleLight() {
  server.send(200, "text/plain", String(analogRead(lightPin)));
}

void setup() {
  // Khởi động Serial để theo dõi thông tin debug
  Serial.begin(9600);
  Serial.println("Kế2222t nối đến WiFi");
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  // Kết nối WiFi
  WiFi.begin(ssid, password);
  Serial.println("Kết nối đến WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Đã kết nối thành công!");
  server.on("/light", handleLight);
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

  pinMode(lightPin, INPUT);


  delay(1000);
}

void loop() {
  server.handleClient();  // Xử lý các yêu cầu từ client
}