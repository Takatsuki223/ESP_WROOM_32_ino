#include<TFT_eSPI.h>

#include"ThinkBold28.h"
#include"ThinkBold32.h"
#include"ThinkBold18.h"
#include"ThinkBold16.h"
#include"Tahoma18.h"

TFT_eSPI tft;
TFT_eSprite sprite = TFT_eSprite(&tft); 

void setup() {
  tft.init();
  tft.setRotation(0);

  sprite.fillScreen(TFT_BLACK);
  sprite.setColorDepth(16);
  sprite.setSwapBytes(true);
  sprite.createSprite(128, 128);
/*
  tft.fillRect(3,3,122,60,TFT_BLUE);
  tft.drawWideLine(13, 44, 44, 13, 1, TFT_WHITE, TFT_WHITE);
  tft.drawWideLine(13, 13, 40, 40, 6, TFT_WHITE, TFT_WHITE);

  tft.fillTriangle(12, 43, 23, 23, 43, 12, TFT_WHITE);
  tft.drawWideLine(40, 40, 40, 47, 4, TFT_WHITE, TFT_WHITE);
  tft.drawWideLine(40, 40, 47, 40, 4, TFT_WHITE, TFT_WHITE);
*/
  tft.unloadFont();

}

void loop() {
  //tft.fillRect(50,5,75,50, TFT_BLUE);
  //tft.fillRect(5,70,120,60, TFT_BLACK);
  sprite.pushSprite(0, 0);  // 将 sprite 显示在指定的屏幕位置 (0, 0)  *
  sprite.fillScreen(TFT_BLACK); // *

  sprite.fillRect(3,3,122,60,TFT_BLUE);
  sprite.drawWideLine(12, 42, 42, 12, 1, TFT_WHITE, TFT_WHITE);
  sprite.drawWideLine(13, 13, 35, 35, 5, TFT_WHITE, TFT_WHITE);

  sprite.fillTriangle(11, 41, 21, 21, 41, 11, TFT_WHITE);
  sprite.drawWideLine(35, 35, 35, 42, 4, TFT_WHITE, TFT_WHITE);
  sprite.drawWideLine(35, 35, 42, 35, 4, TFT_WHITE, TFT_WHITE);


  sprite.setCursor(56, 20);
  sprite.loadFont(ThinkBold32);  
  sprite.setTextColor(TFT_WHITE, TFT_BLUE, 1);
  sprite.println("急行"); 

  sprite.setCursor(14,68);
  sprite.loadFont(ThinkBold28); 
  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.println("泉 岳 寺");

  sprite.setCursor(7,95);
  sprite.setTextColor(TFT_YELLOW, TFT_BLACK, 1);
  sprite.loadFont(ThinkBold16); 
  sprite.println("次  羽田空港第３");

  sprite.setCursor(10,110);
  sprite.loadFont(ThinkBold16); 
  sprite.println(" は    ターミナル");
 
  delay(3000);

  //tft.fillRect(50,5,75,50, TFT_BLUE);
  //tft.fillRect(5,70,120,60, TFT_BLACK);
  sprite.pushSprite(0, 0);  // 将 sprite 显示在指定的屏幕位置 (0, 0)  *
  sprite.fillScreen(TFT_BLACK);//*

  sprite.fillRect(3,3,122,60,TFT_BLUE);
  sprite.drawWideLine(12, 42, 42, 12, 1, TFT_WHITE, TFT_WHITE);
  sprite.drawWideLine(13, 13, 35, 35, 5, TFT_WHITE, TFT_WHITE);

  sprite.fillTriangle(11, 41, 21, 21, 41, 11, TFT_WHITE);
  sprite.drawWideLine(35, 35, 35, 42, 4, TFT_WHITE, TFT_WHITE);
  sprite.drawWideLine(35, 35, 42, 35, 4, TFT_WHITE, TFT_WHITE);

  sprite.setCursor(63, 13);
  sprite.loadFont(ThinkBold28);  
  sprite.setTextColor(TFT_WHITE, TFT_BLUE, 1);
  sprite.println("急行"); 

  sprite.setCursor(50, 42);
  sprite.loadFont(ThinkBold18);  
  sprite.setTextColor(TFT_WHITE, TFT_BLUE, 1);
  sprite.println("Express"); 


  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.setCursor(24,105);
  sprite.loadFont(Tahoma18);
  sprite.println("Sengakuji");

  sprite.setCursor(6,73);
  sprite.loadFont(ThinkBold32);
  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.println("泉 岳 寺"); 

  delay(3000);
  tft.unloadFont();

}