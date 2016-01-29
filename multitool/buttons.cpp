#include <SPI.h>
#include <TFTv2.h>

#include "ui.h"
#include "buttons.h"

void updateButts(){

}

void bgButts(){

  Tft.fillRectangle(0,0,240,320,WHITE);
  drawTitle("Buttons",5,BLUE);

  Tft.fillCircle(80,104,20,GRAY1);
  Tft.fillCircle(160,104,20,GRAY1);

  Tft.fillCircle(80,158,20,GRAY1);
  Tft.fillCircle(160,158,20,GRAY1);

  Tft.fillCircle(80,212,20,GRAY1);
  Tft.fillCircle(160,212,20,GRAY1);

  Tft.fillCircle(80,266,20,GRAY1);
  Tft.fillCircle(160,266,20,GRAY1);
}
