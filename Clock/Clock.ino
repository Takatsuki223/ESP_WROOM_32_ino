// 获取网络时间相关库
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TFT_eSPI.h>

#include <ArduinoJson.h>
#include <HTTPClient.h> // 用于HTTP请求 

#include "img.h"//导入底图

#include "FinalFrontier20.h"
#include "FinalFrontier24.h"
#include "FinalFrontier28.h"
#include "FinalFrontier40.h"
#include "Tahoma16.h"
#include "AL15.h"  //√
// 网络时间相关定义
const char *ssid = "225";           // WiFi账号
const char *password = "gtxytygal";  // WiFi密码
const char* weatherAPI = "https://restapi.amap.com/v3/weather/weatherInfo?key=289d14d0ad7118b61509dd5b1a109ca6&city=610116&extensions=base";
//天气API配置

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com");  // NTP服务器地址
// TFT相关定义
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);  // 创建一个 TFT_eSprite 对象，tft 是你的 TFT 显示对象

int WC = 0;
String TT = "0"; //保存温度
String WW  = "0"; //保存天气

void setup() {
  // ===网络时间初始化设定===
  Serial.begin(115200);  // 初始化串口通信，波特率为115200
  // 连接WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {  // 等待WiFi连接成功
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");  
  Serial.println(WiFi.localIP());    
  timeClient.begin();               // 初始化NTPClient
  timeClient.setTimeOffset(28800);  // 设置时间偏移为28800秒（8小时）

  // ===TFT初始化设定===
  tft.begin();                    // 初始化显示寄存器
  tft.setRotation(0);             // 设置显示屏旋转角度（0表示不旋转，根据需要调整）
  sprite.setColorDepth(16);       // 设置颜色深度（根据你的需求）
  sprite.setSwapBytes(true);      // 设置字节顺序，将RGB颜色顺序转换为BGR以正确显示颜色。
  sprite.createSprite(128, 128);  // 创建一个128x128像素的绘图窗口

}

void loop() {

  timeClient.update();                                  // 更新时间信息
  unsigned long epochTime = timeClient.getEpochTime();  // 获取当前时间的时间戳
  
  struct tm *ptm = gmtime((time_t *)&epochTime);

  int currentYear = ptm->tm_year + 1900;              // 获取年份
  int currentMonth = ptm->tm_mon + 1;                 // 获取月份
  int currentMonthDay = ptm->tm_mday;                 // 获取月份中的日期
  int currentWeekDay = ptm->tm_wday;                  // 获取星期几
  int currentHour = ptm->tm_hour;  // 获取时
  int currentMin = ptm->tm_min;    // 获取分
  int currentSec = ptm->tm_sec;    // 获取秒

  const char weekdays[8][10] = {"0","周一","周二","周三","周四","周五","周六","周日" };
  
  Serial.println("Epoch Time:" + String(epochTime));
  Serial.println(timeClient.getFormattedTime());

  sprite.fillScreen(TFT_BLACK);              // 清屏
  sprite.pushImage(0, 0, 128, 128, img);  // 显示底图

  if(WC == 299){
    
    WC = 0;
    Serial.println(WC);
   
  }else if(WC == 0){
    WC++;
    Serial.println("GetWeather!");
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
    String T = doc["lives"][0]["temperature"];
    String W = doc["lives"][0]["weather"];
    Serial.println("T:" + T);
    Serial.println("W:" + W);
    TT = T;
    WW = W;
  } else {  
    Serial.print("Error on sending GET: ");  
    Serial.println(httpCode);  
  }
    
  }else{
    WC++;
    Serial.println(WC);
  }

  sprite.setCursor(32,6);
  sprite.loadFont(FinalFrontier24);//时后冒号
  sprite.print(":");

  sprite.setCursor(73,4);
  sprite.loadFont(FinalFrontier28);//分后冒号
  sprite.print(":");

  sprite.setCursor(7, 28); 
  sprite.loadFont(FinalFrontier20);                                           // 设定打印位置
  sprite.print(String(currentMonth) + "/" + String(currentMonthDay));  // 打印 月/日  

  sprite.setCursor(5,95);
  sprite.loadFont(FinalFrontier20);
  sprite.print(TT);

  sprite.setCursor(26,95);
  sprite.loadFont(Tahoma16);
  sprite.print("℃");

  sprite.setCursor(5,113);
  sprite.loadFont(AL15);
  sprite.print(WW);

  if(currentHour < 10)
  {
    sprite.setCursor(3,6);                                  
    sprite.loadFont(FinalFrontier24);                                       
    sprite.print("0" + String(currentHour));//时
  }else if(currentHour >= 10 && currentHour < 20){
    sprite.setCursor(9,6);                                  
    sprite.loadFont(FinalFrontier24);    //1开头的时                                    
    sprite.print(String(currentHour));
  }else{
    sprite.setCursor(3,6);                                  
    sprite.loadFont(FinalFrontier24);                                       
    sprite.print(String(currentHour));
  }
  

  if(currentMin < 10)
  {
    sprite.setCursor(39,5);
    sprite.loadFont(FinalFrontier28);
    sprite.print("0" + String(currentMin)); //分
  }else if(currentMin >= 10 && currentMin < 20){
    sprite.setCursor(43,5);
    sprite.loadFont(FinalFrontier28);
    sprite.print(String(currentMin));
  }else{
    sprite.setCursor(40,5);
    sprite.loadFont(FinalFrontier28);
    sprite.print(String(currentMin));
  }
  
  if(currentSec < 10)
  {
    sprite.setCursor(80,5);
    sprite.loadFont(FinalFrontier40);           // 设定显示字体
    sprite.print("0" + String(currentSec));  // 打印 秒

  }else{
    sprite.setCursor(82, 5);          // 设定打印位置
    sprite.loadFont(FinalFrontier40);           // 设定显示字体
    sprite.print(currentSec);  // 打印 秒
  }

  sprite.pushSprite(0, 0);  // 将 sprite 显示在指定的屏幕位置 (0, 0)  

  tft.unloadFont();
  sprite.unloadFont();
  delay(1000);
}