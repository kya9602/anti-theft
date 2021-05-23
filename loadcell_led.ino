#include "HX711.h"
#define calibration_factor -7050.0 
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);
int LED = 5;
int val = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");
  scale.set_scale(calibration_factor); 
  scale.tare();
  Serial.println("Readings:");
  pinMode(LED,OUTPUT);
}
void loop() {
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.println(" lbs");
  val = map(scale.get_units(),0,40,0,255);
  analogWrite(LED,val);
  delay(50);
}
