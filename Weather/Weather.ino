#include <SPI.h>  
#include <TFT_eSPI.h> // 引入TFT库  
#include <HTTPClient.h> // 用于HTTP请求  
#include <WiFi.h>
#include <ArduinoJson.h>  
//#include "nlohmann\json.hpp"
  
// WiFi配置  
const char* ssid = "225";  
const char* password = "gtxytygal";  
  
// 天气API配置（请替换为实际的API和参数）  
const char* weatherAPI = "https://restapi.amap.com/v3/weather/weatherInfo?key=289d14d0ad7118b61509dd5b1a109ca6&city=610116&extensions=base";  
  
TFT_eSPI tft = TFT_eSPI(); // 初始化TFT对象  
  
void setup() {  
  Serial.begin(115200);  
  tft.begin(); // 初始化TFT显示屏  
  tft.fillScreen(TFT_BLACK); // 清屏为黑色  
  tft.setCursor(10, 10); // 设置文本显示位置  
  tft.setTextSize(2); // 设置文本大小  
  tft.setTextColor(TFT_WHITE); // 设置文本颜色  
  
  // 连接到WiFi  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");  
  Serial.println(WiFi.localIP());  
}  
  
void loop() {  
  // 从API获取天气数据  
  HTTPClient http;  
  http.begin(weatherAPI);  
  int httpCode = http.GET();  
  if(httpCode > 0) {  
    String response = http.getString();  
    Serial.println(response);
    StaticJsonDocument<100> doc;
    DeserializationError error = deserializeJson(doc, response);  
      if (error) {  
    Serial.println("Failed to parse JSON");  
    return;  
    }
    String INFO = doc["info"];
    Serial.println(INFO);
    String T = doc["lives"][0]["temperature"];   
    Serial.println(T);

  } else {  
    Serial.print("Error on sending GET: ");  
    Serial.println(httpCode);  
  }  
  http.end(); // 结束HTTP连接  
  delay(1000); // 每分钟更新一次天气数据，你可以根据需要调整这个值  
}