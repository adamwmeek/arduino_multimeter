#include <SPI.h>
#include <TFTv2.h>
#include "ui.h"

void drawTitle(char * title, unsigned int offset, unsigned int color){
  Tft.fillRectangle(0,0,240,50,color);
  Tft.drawString(title,30+offset,10,4,WHITE);
  Tft.drawChar('<',0,10,4,WHITE);
  Tft.drawChar('>',215,10,4,WHITE);
}
void drawBottomPannel(unsigned int color){
  Tft.fillRectangle(0,230,240,90, GRAY1);
  Tft.fillCircle(202,277,35,BLACK);
  Tft.fillCircle(200,275,35,color);
}
