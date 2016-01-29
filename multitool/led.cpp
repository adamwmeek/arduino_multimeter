#include <SPI.h>
#include <TFTv2.h>

#include "ui.h"
#include "led.h"

void updateLED(){

  if(digitalRead(22) == HIGH){
    Tft.fillCircle(80,104,20,GREEN);
  }
  else{
    Tft.fillCircle(80,104,20,GRAY1);
  }

  if(digitalRead(24) == HIGH){
    Tft.fillCircle(80,158,20,GREEN);
  }
  else{
    Tft.fillCircle(80,158,20,GRAY1);
  }

  if(digitalRead(26) == HIGH){
    Tft.fillCircle(80,212,20,GREEN);
  }
  else{
    Tft.fillCircle(80,212,20,GRAY1);
  }

  if(digitalRead(28) == HIGH){
    Tft.fillCircle(80,266,20,GREEN);
  }
  else{
    Tft.fillCircle(80,266,20,GRAY1);
  }

  if(digitalRead(30) == HIGH){
    Tft.fillCircle(160,104,20,GREEN);
  }
  else{
    Tft.fillCircle(160,104,20,GRAY1);
  }

  if(digitalRead(32) == HIGH){
    Tft.fillCircle(160,158,20,GREEN);
  }
  else{
    Tft.fillCircle(160,158,20,GRAY1);
  }

  if(digitalRead(34) == HIGH){
    Tft.fillCircle(160,212,20,GREEN);
  }
  else{
    Tft.fillCircle(160,212,20,GRAY1);
  }

  if(digitalRead(36) == HIGH){
    Tft.fillCircle(160,266,20,GREEN);
  }
  else{
    Tft.fillCircle(160,266,20,GRAY1);
  }
}

void bgLED(){

  Tft.fillRectangle(0,0,240,320,WHITE);
  drawTitle("LED",50,GREEN);

  Tft.fillCircle(80,104,20,GRAY1);
  Tft.fillCircle(160,104,20,GRAY1);

  Tft.fillCircle(80,158,20,GRAY1);
  Tft.fillCircle(160,158,20,GRAY1);

  Tft.fillCircle(80,212,20,GRAY1);
  Tft.fillCircle(160,212,20,GRAY1);

  Tft.fillCircle(80,266,20,GRAY1);
  Tft.fillCircle(160,266,20,GRAY1);

  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  
  pinMode(30, INPUT);
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(36, INPUT);
}
