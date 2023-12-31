#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Redmi Note 9S";
const char* password = "qazwsx123";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);

#include <TinyStepper.h>
#define HALFSTEPS 4096
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
TinyStepper stepper(HALFSTEPS, IN1, IN2, IN3, IN4);
void handleStepper() {
  String angleString = server.arg("angle");
  int angle = angleString.toInt();
  Serial.println(angle);
  stepper.Move(angle, 3);
  server.send(200, "text/plain", "success");
}

const int gasPin = A0;
void handleGas() {
  server.send(200, "text/plain", String(analogRead(gasPin)));
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
  server.on("/gas", handleGas);
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

  pinMode(gasPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(1000);
}

void loop() {
  server.handleClient();  // Xử lý các yêu cầu từ client
}
