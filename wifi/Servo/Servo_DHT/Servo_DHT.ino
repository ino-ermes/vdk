#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Wifiofme";
const char* password = "12345678";

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

#include <DHT.h>
DHT dht(D4, DHT11);
float temperature = 0.0;
float humidity = 0.0;
float tmp = 0.0;
void handleGetHumidity() {
    tmp = dht.readHumidity();
    if(!isnan(tmp)) humidity = tmp;
    server.send(200, "text/plain", String(humidity));
}
void handleGetTemperature() {
    tmp = dht.readTemperature();
    if(!isnan(tmp)) temperature = tmp;
    server.send(200, "text/plain", String(temperature));
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
  server.on("/humidity", handleGetHumidity);
  server.on("/temperature", handleGetTemperature);
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
  dht.begin();
  delay(1000);
}

void loop() {
  server.handleClient(); // Xử lý các yêu cầu từ client
}
