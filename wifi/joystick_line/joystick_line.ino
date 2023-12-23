#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Redmi Note 9S";
const char* password = "qazwsx123";

// Khởi tạo đối tượng máy chủ web
ESP8266WebServer server(80);


const int xPin = A0;
const int btnPin = D1;
void handleJoystick() {
  server.send(200, "text/plain", String(analogRead(xPin)) + "," + digitalRead(btnPin));
}

const int linePin = D5;
void handleLine() {
  server.send(200, "text/plain", String(digitalRead(linePin)));
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
  server.on("/line", handleLine);
  server.on("/joystick", handleJoystick);

  // Khởi động máy chủ
  server.enableCORS(true);
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  pinMode(btnPin, INPUT_PULLUP);
  pinMode(linePin, INPUT);


  delay(1000);
}

void loop() {
  server.handleClient(); // Xử lý các yêu cầu từ client
}
