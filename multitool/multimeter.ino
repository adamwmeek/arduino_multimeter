/**
 * Arduino Multimeter
 * @author Adam Meek
 * 
 * A device to measure and visualize simple analog and 
 * digital signals
 * 
 * Current Features:
 * * Display 4 digital channels
 * * Display analog channel
 * * Resistance meter
 * * Virtual LEDs
 * 
 * Todo:
 * 
 * * L meter
 * * C meter
 * * Quick buttons
 * * Digital frequency measurments
 * * Signal recording
 * * Display FFT of analog channel
 * * Pin selector
 * 
 */

#include <SPI.h>
#include <TFTv2.h>
#include <SeeedTouchScreen.h>

#include "ui.h"
#include "digital.h"
#include "analog.h"
#include "rcl.h"
#include "led.h"
#include "buttons.h"

typedef enum {RCL, ANALOG, DIGITAL, LED, BUTTS} statetype;
statetype state = RCL;
TouchScreen ts = TouchScreen(XP,YP,XM,YM);

void nextSt();
void prevSt();

void setup() {

  Tft.TFTinit();
  bgRCL();
}

void loop() {

  if(state == DIGITAL){
    updateDigital();
  }
  else if(state == ANALOG){
    updateAnalog();
  }
  else if(state == RCL){
    updateRCL();
  }
  else if(state == LED){
    updateLED();
  }
  else if(state == BUTTS){
    updateButts();
  }
  else{
    //uh oh! Invalid state! Cheese it!
  }

  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);
  
  if (p.z > __PRESURE) {

    // Navigation buttons
    if(p.y < 50){

      if(p.x < 30){
        prevSt();
      }

      if(p.x > 210){
        nextSt();   
      }
    }
  } 
}

// -- State Transition Fncs -- //
void nextSt(){

  switch(state){

    case RCL:
      bgAnalog();
      state = ANALOG;
      break;
      
    case ANALOG:
      bgDigi();
      state = DIGITAL;
      break;

    case DIGITAL: 
      bgLED();
      state = LED;
      break;

    case LED:
      bgButts();
      state = BUTTS;
      break;

    case BUTTS:
      break;
  }
}
void prevSt(){

  switch(state){

    case RCL:
      break;
    
    case ANALOG:
      bgRCL();
      state = RCL;
      break;
      
    case DIGITAL: 
      bgAnalog();
      state = ANALOG;
      break;

    case LED:
      bgDigi();
      state = DIGITAL;
      break;

    case BUTTS:
      bgLED();
      state = LED;
      break;
    
  }
}

