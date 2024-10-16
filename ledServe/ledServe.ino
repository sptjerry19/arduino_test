//Khai báo thư viện
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "managerData.h"
#include "admin.h"
#include "homePage.h"
#include "controlPage.h"

// Tạo một đối tượng JsonDocument có dung lượng 100 byte
StaticJsonDocument<100> doc;
StaticJsonDocument<100> events;

#define RX_PIN 4 // Chân RX của EspSoftwareSerial
#define TX_PIN 5 // Chân TX của EspSoftwareSerial
// Tạo một đối tượng SoftwareSerial
SoftwareSerial mySerial(RX_PIN , TX_PIN ); // RX, TX

// dht
const int dhtPin = D4;

// led
const int ledStop = D5;
const int ledFoward = D6;
const int led = D7;
const int ledChangeMode = D8;

//Khai báo thông tin wifi
const char* ssid = "cheese";
const char* password = "hoilamgi";

//Khai báo đối tượng webserver, sử dụng port 80
ESP8266WebServer server(80);

//Khai báo chân LED
// const int LED_PIN = D4;
// const int LED_PIN1 = D2;

// khởi tạo số người truy cập
int count = 0;

// Khai báo đối tượng DHTesp
  DHT dht(dhtPin, DHT11);

//Hàm setup của Arduino IDE
void setup() {
  // led
  pinMode(ledStop, OUTPUT);
  pinMode(ledFoward, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(ledChangeMode, OUTPUT);
  digitalWrite(ledStop, 0);
  digitalWrite(ledFoward, 0);
  // Khởi tạo đối tượng DHTesp
  dht.begin();
  //Khởi tạo cổng nối tiếp
  Serial.begin(115200);
  // Khởi tạo cổng nối tiếp ảo
  mySerial.begin(9600);
  //Khởi tạo webserver
  setupServer();
}

//Hàm loop của Arduino IDE
void loop() {
  //Xử lý các yêu cầu từ người dùng
  server.handleClient();
}

//Hàm khởi tạo webserver
void setupServer() {
  //Thiết lập chân LED là output
  // pinMode(LED_PIN, OUTPUT);
  // pinMode(LED_PIN1, OUTPUT);
  // //Tắt LED
  // digitalWrite(LED_PIN, 0);
  // digitalWrite(LED_PIN1, 0);

  //phát wifi
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("AutoTeam10", "69696969");

  //Kết nối wifi
  // Serial.print("Connecting to ");
  // Serial.println(ssid);
  // WiFi.begin(ssid, password);
  // while (WiFi.waitForConnectResult() != WL_CONNECTED) {
  //   delay(100);
  //   Serial.print(".");
  // }
  server.begin();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //Định nghĩa các hàm xử lý yêu cầu từ người dùng
  //Nếu người dùng truy cập địa chỉ IP của ESP8266, trả về giao diện web để điều khiển LED
  server.on("/", handleRoot);

  //
  server.on("/index", [] {
    server.send(200, "text/html", readData("index.html"));
  });

  // send data to webserve
  server.on("/data", []() {
    // tạo và gán nhiệt độ, độ ẩm -> json
    // dht.readTemperature();
    // dht.readHumidity();
    float temperature = random(10,40);
    float humidity = dht.readHumidity();

    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    // Trả về dữ liệu JSON
    String json;
    serializeJson(doc.as<JsonVariantConst>(), json);
    // Serial.println(json);
    server.send(200, "application/json", json);
  });


  //đếm số người truy cập:
  server.on("/count", [] {
    Serial.println(String("co nguoi truy cap: ") + count);
    server.send(200, "text/plain", String("so nguoi truy cap: ") + count);
  });

  //Nếu người dùng truy cập địa chỉ IP/led/on, bật LED và trả về thông báo
  server.on("/control", [] {
    server.send(200, "text/html", control);
  });

  //Nếu người dùng truy cập địa chỉ IP/led/on, bật LED và trả về thông báo
  server.on("/led/on", handleLedOn);

  //Nếu người dùng truy cập địa chỉ IP/led/off, tắt LED và trả về thông báo
  server.on("/led/off", handleLedOff);

  //Nếu người dùng truy cập địa chỉ IP/led/off, tắt LED và trả về thông báo
  server.on("/auto/on", handleAutoOn);

  //Nếu người dùng truy cập địa chỉ IP/led/off, tắt LED và trả về thông báo
  server.on("/auto/off", handleAutoOff);

  //Nếu người dùng truy cập địa chỉ IP/motor/left, tắt LED và trả về thông báo
  server.on("/motor/left", handleMotoLeft);

  //Nếu người dùng truy cập địa chỉ IP/motor/right, tắt LED và trả về thông báo
  server.on("/motor/right", handleMotoRight);

  //Nếu người dùng truy cập địa chỉ IP/motor/foward, tắt LED và trả về thông báo
  server.on("/motor/foward", handleMotoFoward);

  //Nếu người dùng truy cập địa chỉ IP/motor/foward, tắt LED và trả về thông báo
  server.on("/motor/return", handleMotoReturn);

  //
  server.on(
    "/transFile", HTTP_ANY, [] {
      server.send(200, "text/html", "<meta charset='utf-8'"
                                    "<form method='POST' action='/transFile' enctype='multipart/form-data'>"
                                    "<input type='file' name='chon File'>"
                                    "<input type='submit' value='gui File'>"
                                    "</form>");
    },
    [] {
      HTTPUpload& file = server.upload();

      if (file.status == UPLOAD_FILE_START) {
        Serial.println("bat dau gui: " + file.filename);
      } else if (file.status == UPLOAD_FILE_WRITE) {
        saveData("index.html", (const char*)file.buf, file.currentSize);
      }
    });

  //Nếu người dùng truy cập địa chỉ IP không hợp lệ, trả về mã lỗi 404
  server.onNotFound(handleNotFound);

  //Bắt đầu webserver
  server.begin();
  Serial.println("Webserver started");
}

//Hàm xử lý yêu cầu gốc
void handleRoot() {
  Serial.println(String("Có người truy cập: ") + count++);
  //Gửi biến chứa mã nguồn html cho người dùng
  server.send(200, "text/html", admin);
}

//Hàm xử lý yêu cầu bật LED
void handleLedOn() {
  //Bật LED
  digitalWrite(led, 1);
  sendEventAuto("ledon");
}

//Hàm xử lý yêu cầu tắt LED
void handleLedOff() {
  //Tắt LED
  digitalWrite(led, 0);
  sendEventAuto("ledoff");
}

// hàm xử lý bật chế độ auto
void handleAutoOn() {
  digitalWrite(ledChangeMode, 1);
  sendEventAuto("autoON");
}

// hàm xử lý tắt chế độ auto
void handleAutoOff() {
  digitalWrite(ledFoward, 0);
  digitalWrite(ledChangeMode, 0);
  digitalWrite(ledStop, 1);
  sendEventAuto("autoOFF");
}

// xử lý sự kiện oto rẽ trái
void handleMotoLeft() {
  //Tắt LED
  digitalWrite(ledFoward, 0);
  digitalWrite(ledStop, 0);
  sendEventAuto("retrai");
}

// xử lý sự kiện oto đi thẳng
void handleMotoFoward() {
  //Tắt LED
  digitalWrite(ledFoward, 0);
  digitalWrite(ledStop, 0);
  sendEventAuto("dithang");
}

// xử lý sự kiện oto đi lùi
void handleMotoReturn() {
  //Tắt LED
  digitalWrite(ledStop, 0);
  digitalWrite(ledFoward, 1);
  sendEventAuto("dilui");
}

// xử lý sự kiện oto rẽ phải
void handleMotoRight() {
  //Tắt LED
  digitalWrite(ledFoward, 0);
  digitalWrite(ledStop, 0);
  sendEventAuto("rephai");
}

//Hàm xử lý yêu cầu không hợp lệ
void handleNotFound() {
  //Gửi mã lỗi 404 cho người dùng
  server.send(404, "text/plain", "Khong tim thay trang Web");
}

// xử lý sự kiện
void sendEventAuto(String event) {
  events["event"] = event;
  // Chuyển đổi đối tượng JsonDocument thành chuỗi JSON và gửi nó qua cổng nối tiếp ảo
  serializeJson(events, mySerial);
  mySerial.println();

  // Chuyển đổi đối tượng JsonDocument thành chuỗi JSON và gửi nó qua cổng nối tiếp thật
  serializeJson(events, Serial);
  Serial.println();
  server.send(200, "text/html", control);
}
