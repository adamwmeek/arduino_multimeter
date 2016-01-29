#include <SPI.h>
#include <TFTv2.h>

#include "ui.h"
#include "analog.h"

#define ORANGE 0xfc00

// ints, because A/D values are 10-bit
int analogChan[240];
float volts = 0;

void drawAnalogPixel(unsigned int index, unsigned int value, int color){
  
    //This function maps analog values to screen position
    //Formula: y = -70/1024 * x + 130
    
    unsigned int mapped = 35 * value;

    //Since I'm diving by a power of 2, I'm gonna save clock cycles by 
    //shifting, rather than dividing!
    mapped = mapped >> 9;
    mapped = 130 - mapped;

    Tft.setPixel(index, mapped, color);
    
}

void updateAnalog(){

  for(unsigned int i=0; i<239; i++){
    drawAnalogPixel(i,analogChan[i], WHITE);
    analogChan[i] = analogChan[i+1];
    drawAnalogPixel(i,analogChan[i], BLUE);
  }

  // read in new analog value
  drawAnalogPixel(239, analogChan[239], WHITE);
  unsigned int newVal = analogRead(8);
  analogChan[239] = newVal;
  drawAnalogPixel(239, newVal, BLUE);

  Tft.drawFloat(volts,3,20,250,4,GRAY1);
  volts = newVal * 0.00489;
  Tft.drawFloat(volts,3,20,250,4,WHITE);  
}

void bgAnalog(){
  
  Tft.fillRectangle(0,0,240,320,WHITE);
  drawTitle("Analog",10,ORANGE);
  drawBottomPannel(ORANGE);
  Tft.drawHorizontalLine(0,140,240,BLACK);
  Tft.drawString("Volts",15,290,2,YELLOW);
  Tft.drawString("Hertz",90,290,2,WHITE);
}
