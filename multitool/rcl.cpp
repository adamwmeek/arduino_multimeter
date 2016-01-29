#include <SPI.h>
#include <TFTv2.h>

#include "ui.h"
#include "rcl.h"

#define KNOWN 100000
float resistance = 0;

void updateRCL(){

  Tft.drawFloat(resistance, 0, 60, 85, 3, WHITE);
  unsigned int volt = analogRead(9);
  resistance = (KNOWN * 1024/volt) - KNOWN;
  if(resistance < 0){
    resistance = 0;
  }
  Tft.drawFloat(resistance, 0, 60, 85, 3, BLACK);

  delay(200);
}

void bgRCL(){

  Tft.fillRectangle(0,0,240,320,WHITE);
  drawTitle("Meter",25,RED);
  Tft.drawHorizontalLine(0,140,240,BLACK);
  Tft.drawHorizontalLine(0,230,240,BLACK);
  Tft.fillCircle(30,95,20,RED);
  Tft.drawString("R",200,85,3,BLACK);
    
  Tft.fillCircle(30,185,20,GRAY1);
  Tft.drawString("C",200,175,3,BLACK);
  
  Tft.fillCircle(30,275,20,GRAY1);
  Tft.drawString("L",200,265,3,BLACK);

  pinMode(40, OUTPUT);
  digitalWrite(40, HIGH);
}
