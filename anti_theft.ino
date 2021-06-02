#include "HX711.h"
#define calibration_factor -7050.0
#define DOUT  3
#define CLK  2  
HX711 scale(DOUT, CLK); 
int count = 0;
int led = 0;

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  //Serial.println("HX711 scale TEST");//  
  scale.set_scale(calibration_factor); 
  scale.tare();
}

void loop() {
  long hi = scale.read();
  if(count == 0){
    if(hi > 20){
      if(led == 0){
        digitalWrite(13, HIGH);
        delay(500);
        led = 1;
        Serial.println(led);
      }
      if(led ==1){
        digitalWrite(13, LOW);
        count = 1;
        led = 0;       
      }
    }
  }
  if(count == 1){
     if(hi < 15){
      if(led == 0){
        digitalWrite(13, HIGH);
        delay(500);
        count = 0;
        led = 1;
        Serial.println(led);
      }
      if(led ==1){
        digitalWrite(13, LOW);
        led = 0;        
      }
    }
  }
}
