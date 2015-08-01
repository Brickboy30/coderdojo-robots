#include <Adafruit_NeoPixel.h>

int right_forward = 5;
int right_reverse = 3;
int left_forward = 6;
int left_reverse = 2;
int power_forward_right = 200; /* half power on turns */
int power_forward_left = 200; /* half power on turns */
int waitTime = 100;
#define LEDPIN  7 // connect the Data In pin
#define NUMBER_PIEXELS 12// connect the Data In pin
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIEXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup(void){
  pinMode(right_forward, OUTPUT);
  pinMode(right_reverse, OUTPUT); 
  pinMode(left_forward, OUTPUT); 
  pinMode(left_reverse, OUTPUT);
  // turn all off
  digitalWrite(right_forward, LOW);
  digitalWrite(right_reverse, LOW);
  digitalWrite(left_forward, LOW);
  digitalWrite(left_reverse, LOW);

}
void loop(void){  

  
}

void turn_right(void){
  Serial.println("turning right");
  analogWrite(right_forward, LOW);
  analogWrite(right_reverse, power_forward_right);
  analogWrite(left_forward, power_forward_left);
  analogWrite(left_reverse, LOW);

}

void move_forward(void) {
  Serial.println("moving forward");
  analogWrite(right_forward, power_forward_right);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, power_forward_left);
  analogWrite(left_reverse, LOW);
}

void move_backward(void){
  Serial.println("moving backward");
  analogWrite(right_reverse, power_forward_right);
  analogWrite(right_forward, LOW);
  analogWrite(left_reverse, power_forward_left);
  analogWrite(left_forward, LOW);
}

void turn_left(void){
  Serial.println("turning left");
  analogWrite(right_forward, power_forward_right);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, LOW);
  analogWrite(left_reverse, power_forward_left);
}

void do_nothing(void){
  Serial.println("Doing Nothing");
  analogWrite(right_forward, LOW);
  analogWrite(right_reverse, LOW);
  analogWrite(left_forward, LOW);
  analogWrite(left_reverse, LOW);
  
}

void mainMenu() {
   strip.setPixelColor(0, 255, 0, 0);     // make the 1st pixel red
   strip.setPixelColor(1, 0, 255, 0);     // make the 2nd pixel green
   strip.setPixelColor(2, 0, 0, 255);     // make the 3rd pixel blue
   strip.setPixelColor(3, 255, 255, 255); // make the 4th pixel white
   strip.setPixelColor(4, 255, 255, 0);   // make the 5th pixel yellow
   strip.setPixelColor(5, 0, 255, 255);   // make the 6th pixel aqua
   strip.setPixelColor(6, 255, 0, 255);   // make the 7th pixel fuchsia
   strip.setPixelColor(7, 200, 130, 0);   // make the 8th pixel orange (changed from 255, 165, 0)
   strip.setPixelColor(8, 80, 0, 80);     // make the 9th pixel purple
   strip.setPixelColor(9, 143, 188, 143); // make the 10th pixel DarkSeaGreen
   strip.setPixelColor(10, 218, 165, 32);  // make the 11th pixel Goldenrod
   strip.setPixelColor(11, 127, 255, 212);  // make the 11th pixel Aquamarine
   strip.show(); // must use to refresh the strip
}

void colorWipe(uint32_t color, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
      delay(wait);
  }
}
