#include <SPI.h>
#include <TFTv2.h>

#include "ui.h"
#include "digital.h"

char digiChan0[240];
char digiChan1[240];
char digiChan2[240];
char digiChan3[240];

void updateDigital(){
  for(int i=0;i < 239; i++){

    //Clear old marking
    if(digiChan0[i] > 0){
      Tft.setPixel(i,60,WHITE);
    }
    else{
      Tft.setPixel(i,85,WHITE);
    }

    if(digiChan1[i] > 0){
      Tft.setPixel(i,105,WHITE);
    }
    else{
      Tft.setPixel(i,130,WHITE);
    }

    if(digiChan2[i] > 0){
      Tft.setPixel(i,150,WHITE);
    }
    else{
      Tft.setPixel(i,175,WHITE);
    }

    if(digiChan3[i] > 0){
      Tft.setPixel(i,195,WHITE);
    }
    else{
      Tft.setPixel(i,220,WHITE);
    }

    //Rotate buffer
    digiChan0[i] = digiChan0[i+1];
    digiChan1[i] = digiChan1[i+1];
    digiChan2[i] = digiChan2[i+1];
    digiChan3[i] = digiChan3[i+1];
    
    //Redraw
    if(digiChan0[i] > 0){
      Tft.setPixel(i,60,BLUE);
    }
    else{
      Tft.setPixel(i,85,BLUE);
    }

    if(digiChan1[i] > 0){
      Tft.setPixel(i,105,BLUE);
    }
    else{
      Tft.setPixel(i,130,BLUE);
    }

    if(digiChan2[i] > 0){
      Tft.setPixel(i,150,BLUE);
    }
    else{
      Tft.setPixel(i,175,BLUE);
    }

    if(digiChan3[i] > 0){
      Tft.setPixel(i,195,BLUE);
    }
    else{
      Tft.setPixel(i,220,BLUE);
    }
  }

  //Read in new values
  
  if(digitalRead(22) == HIGH){
    digiChan0[239] = 1;
    Tft.setPixel(239,60,BLUE);
  }
  else{
    digiChan0[239] = 0;
    Tft.setPixel(239,85,BLUE);
  }
  //--
  if(digitalRead(24) == HIGH){
    digiChan1[239] = 1;
    Tft.setPixel(239,105,BLUE);
  }
  else{
    digiChan1[239] = 0;
    Tft.setPixel(239,130,BLUE);
  }
  //--
  if(digitalRead(26) == HIGH){
    digiChan2[239] = 1;
    Tft.setPixel(239,150,BLUE);
  }
  else{
    digiChan2[239] = 0;
    Tft.setPixel(239,175,BLUE);
  }
  //--
  if(digitalRead(28) == HIGH){
    digiChan3[239] = 1;
    Tft.setPixel(239,195,BLUE);
  }
  else{
    digiChan3[239] = 0;
    Tft.setPixel(239,220,BLUE);
  }
}

void bgDigi(){
  
  Tft.fillRectangle(0,0,240,320,WHITE);
  drawTitle("Digital",10,YELLOW);
  drawBottomPannel(YELLOW);
  Tft.drawHorizontalLine(0,95,240,BLACK);
  Tft.drawHorizontalLine(0,140,240,BLACK);
  Tft.drawHorizontalLine(0,185,240,BLACK);

  // Digital input
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
}
