#include<TFT_eSPI.h>

#include"ThinkBold28.h"
#include"ThinkMedium28.h"
#include"ThinkBold24.h"
#include"ThinkMedium14.h"
#include"ThinkSemiBold16.h"

#include"DengB28.h"
#include"BR28.h"
TFT_eSPI tft;
TFT_eSprite sprite = TFT_eSprite(&tft); 

uint16_t BgColor = tft.color565(90,113,217);
uint16_t TextColor = tft.color565(212,241,250);
uint16_t ENColor = tft.color565(255,220,224);

void setup() {
  tft.init();
  tft.setRotation(0);
  //sprite.fillScreen(TFT_BLACK);

  sprite.setColorDepth(16);
  sprite.setSwapBytes(true);
  sprite.createSprite(128, 128);
  sprite.pushSprite(0, 0);

  sprite.fillRect(6,12,25,25,BgColor);

  sprite.setCursor(10,14);
  sprite.loadFont(ThinkBold24);
  sprite.println("A");

  sprite.setCursor(40,107);
  sprite.loadFont(ThinkSemiBold16);
  sprite.setTextColor(ENColor,TFT_BLACK,1);
  sprite.println("Himeji");
  
  sprite.fillRect(0,49,128,20,BgColor);

  sprite.setCursor(17,53);
  sprite.loadFont(ThinkMedium14);
  sprite.setTextColor(TFT_WHITE,BgColor,1);
  sprite.println("Special Rapid");

  sprite.setCursor(38,13);
  sprite.loadFont(DengB28);
  sprite.setTextColor(TextColor,TFT_BLACK,1);
  sprite.println("新快速");

  sprite.setCursor(21,77);
  sprite.loadFont(BR28);
  sprite.setTextColor(TFT_WHITE,TFT_BLACK,1);
  sprite.println("姫     路");

}

void loop() {
  sprite.pushSprite(0, 0);
  //tft.fillScreen(TFT_BLACK);
  //tft.setSwapBytes(true);


}
