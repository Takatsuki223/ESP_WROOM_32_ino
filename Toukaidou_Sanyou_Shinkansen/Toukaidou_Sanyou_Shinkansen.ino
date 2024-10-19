#include<TFT_eSPI.h>

#include "calibriB24.h"
#include "calibriB28.h"
#include"ThinkBold28.h"
#include"ThinkBold15.h"
#include"ThinkSemiBold28.h"
#include"ThinkSemiBold14.h"

TFT_eSPI tft;
TFT_eSprite sprite = TFT_eSprite(&tft);

uint16_t SC = tft.color565(255,155,180);
uint16_t G = tft.color565(3,246,34);



void setup() {
  tft.init();
  tft.setRotation(0);

  sprite.fillScreen(TFT_BLUE);
  sprite.setColorDepth(16);
  sprite.setSwapBytes(true);
  sprite.createSprite(128, 128);

  tft.unloadFont();

}

void loop() {
  //希望号97 博多
  //tft.fillRect(3,3,122,30,TFT_YELLOW);
  //tft.fillRect(0,70,1228,55,TFT_BLACK);
  sprite.pushSprite(0, 0);  
  sprite.fillScreen(TFT_BLACK); //清屏

  sprite.setTextColor(G, TFT_BLACK, 1);  
  sprite.setCursor(5, 107);           
  sprite.loadFont(ThinkBold15);
  sprite.println("指定席");

  sprite.fillRect(3,3,122,61,TFT_YELLOW);//黄色块          
  sprite.setTextColor(TFT_BLACK, TFT_YELLOW, 1); 
  
  sprite.setCursor(22, 10); 
  sprite.loadFont(ThinkSemiBold28);//日语爱称         
  sprite.println("のぞみ");  

  sprite.loadFont(calibriB28);
  sprite.setCursor(50,40);        //车号
  sprite.println(97);


  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.setCursor(29,73);
  sprite.loadFont(ThinkSemiBold28); 
  sprite.println("博  多");

  sprite.fillRect(74,105,13,17,TFT_WHITE);
  sprite.fillRect(72,107,17,13,TFT_WHITE);
  sprite.fillTriangle(75,120,85,120,80,115,G);
  sprite.fillTriangle(75,106,85,106,80,111,G);
  sprite.fillTriangle(87,108,87,118,82,113,G);  
  sprite.fillTriangle(73,108,73,118,78,113,G);

  sprite.drawWideLine(96,114,106,114,2,TFT_WHITE,TFT_BLACK);
  sprite.drawLine(108,113,108,114,TFT_WHITE);
  sprite.drawLine(110,113,110,114,TFT_WHITE);
  sprite.drawLine(108,111,105,109,TFT_WHITE);
  sprite.drawLine(110,111,107,109,TFT_WHITE);
  sprite.drawLine(105,109,107,107,TFT_WHITE);
  sprite.drawSmoothArc(104,113,10,8,0,360,TFT_RED,TFT_BLACK,1);
  sprite.drawWideLine(98,109,110,119,2,TFT_RED,TFT_RED);


  delay(2500);

  //tft.fillRect(3,3,122,30,TFT_YELLOW);
  //tft.fillRect(0,70,128,55,TFT_BLACK);
  sprite.pushSprite(0, 0);  
  sprite.fillScreen(TFT_BLACK); //清屏

  sprite.setTextColor(G, TFT_BLACK, 1);    
  sprite.setCursor(5, 108);
  sprite.loadFont(ThinkSemiBold14);
  sprite.println("Reserved");

  sprite.fillRect(3,3,122,61,TFT_YELLOW);//黄色色块
  sprite.setTextColor(TFT_BLACK, TFT_YELLOW, 1); 
  
  sprite.setCursor(14, 10); 
  sprite.loadFont(calibriB28);//英语爱称
  sprite.println("NOZOMI");  

  sprite.setCursor(50,40);
  sprite.println(97);//车次


  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.setCursor(22,73);
  sprite.loadFont(calibriB28); //英语爱称
  sprite.println("Hakata");

  sprite.fillRect(74,105,13,17,TFT_WHITE);
  sprite.fillRect(72,107,17,13,TFT_WHITE);
  sprite.fillTriangle(75,120,85,120,80,115,G);
  sprite.fillTriangle(75,106,85,106,80,111,G);
  sprite.fillTriangle(87,108,87,118,82,113,G);  
  sprite.fillTriangle(73,108,73,118,78,113,G);

  sprite.drawWideLine(96,114,106,114,2,TFT_WHITE,TFT_BLACK);
  sprite.drawLine(108,113,108,114,TFT_WHITE);
  sprite.drawLine(110,113,110,114,TFT_WHITE);
  sprite.drawLine(108,111,105,109,TFT_WHITE);
  sprite.drawLine(110,111,107,109,TFT_WHITE);
  sprite.drawLine(105,109,107,107,TFT_WHITE);
  sprite.drawSmoothArc(104,113,10,8,0,360,TFT_RED,TFT_BLACK,1);
  sprite.drawWideLine(98,109,110,119,2,TFT_RED,TFT_RED); 

  delay(2000);
  //樱花573 熊本行

  //tft.fillRect(3,3,122,30,tft.color565(255,155,180));
  //tft.fillRect(0,70,128,55,TFT_BLACK);
  sprite.pushSprite(0, 0);    
  sprite.fillScreen(TFT_BLACK); //清屏
          
  sprite.setTextColor(G, TFT_BLACK, 1);  
  sprite.setCursor(5, 107);         
  sprite.loadFont(ThinkBold15);
  sprite.println("指定席");

  sprite.fillRect(3,3,122,61,SC);   //粉色色块 
  sprite.setTextColor(TFT_WHITE, SC, 1);  
  
  sprite.setCursor(21, 10); 
  sprite.loadFont(ThinkSemiBold28);          
  sprite.println("さくら");//日语爱称  

  sprite.loadFont(calibriB28);
  sprite.setCursor(45,40);
  sprite.println(573);


  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.setCursor(29,73);
  sprite.loadFont(ThinkSemiBold28); 
  sprite.println("熊  本");

  sprite.fillRect(74,105,13,17,TFT_WHITE);
  sprite.fillRect(72,107,17,13,TFT_WHITE);
  sprite.fillTriangle(75,120,85,120,80,115,G);
  sprite.fillTriangle(75,106,85,106,80,111,G);
  sprite.fillTriangle(87,108,87,118,82,113,G);  
  sprite.fillTriangle(73,108,73,118,78,113,G);

  sprite.drawWideLine(96,114,106,114,2,TFT_WHITE,TFT_BLACK);
  sprite.drawLine(108,113,108,114,TFT_WHITE);
  sprite.drawLine(110,113,110,114,TFT_WHITE);
  sprite.drawLine(108,111,105,109,TFT_WHITE);
  sprite.drawLine(110,111,107,109,TFT_WHITE);
  sprite.drawLine(105,109,107,107,TFT_WHITE);
  sprite.drawSmoothArc(104,113,10,8,0,360,TFT_RED,TFT_BLACK,1);
  sprite.drawWideLine(98,109,110,119,2,TFT_RED,TFT_RED);

  delay(2500);

  //tft.fillRect(3,3,122,30,tft.color565(255,155,180));
  //tft.fillRect(0,70,128,55,TFT_BLACK);
  sprite.pushSprite(0, 0); 
  sprite.fillScreen(TFT_BLACK); //清屏

  sprite.setTextColor(G, TFT_BLACK, 1); 
  sprite.setCursor(5, 108);
  sprite.loadFont(ThinkSemiBold14);
  sprite.println("Reserved");

  sprite.fillRect(3,3,122,61,SC);   //粉色色块  
  sprite.setTextColor(TFT_WHITE,SC, 1);  
  
  sprite.setCursor(16, 10); 
  sprite.loadFont(calibriB28);           
  sprite.println("SAKURA");  //英语爱称

  sprite.setCursor(45,40);
  sprite.println(573);


  sprite.setTextColor(TFT_WHITE, TFT_BLACK, 1);
  sprite.setCursor(8,73);
  sprite.loadFont(calibriB24); 
  sprite.println("Kumamoto");

  sprite.fillRect(74,105,13,17,TFT_WHITE);
  sprite.fillRect(72,107,17,13,TFT_WHITE);
  sprite.fillTriangle(75,120,85,120,80,115,G);
  sprite.fillTriangle(75,106,85,106,80,111,G);
  sprite.fillTriangle(87,108,87,118,82,113,G);  
  sprite.fillTriangle(73,108,73,118,78,113,G);

  sprite.drawWideLine(96,114,106,114,2,TFT_WHITE,TFT_BLACK);
  sprite.drawLine(108,113,108,114,TFT_WHITE);
  sprite.drawLine(110,113,110,114,TFT_WHITE);
  sprite.drawLine(108,111,105,109,TFT_WHITE);
  sprite.drawLine(110,111,107,109,TFT_WHITE);
  sprite.drawLine(105,109,107,107,TFT_WHITE);
  sprite.drawSmoothArc(104,113,10,8,0,360,TFT_RED,TFT_BLACK,1);
  sprite.drawWideLine(98,109,110,119,2,TFT_RED,TFT_RED);

  delay(2000);

  tft.unloadFont();
}
