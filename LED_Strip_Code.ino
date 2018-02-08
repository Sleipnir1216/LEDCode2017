#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2
int brightness = 255;
int brightnessbegin = 255;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
}


unsigned int pixels = 0;


void loop() {
randomSmoothLightup();
randomSmoothLightupReverse();
smoothLightup();
smoothLightupBackwards();
pixelBlinkRedGreen(200,5);
for(int i = 0; i < 5; i++){
  randomBlink();
}
}

void randomSmoothLightupReverse(){
  long randomI = random(32, 256);
  long randomP = random(1, 5);
  for(int pNum = 59; pNum >= 0; pNum--){
  switch(randomP){
  case 1:
    strip.setPixelColor(pNum, randomI, 0, 0);
    strip.show();
    delay(50);
    break;
  case 2:
  strip.setPixelColor(pNum, 0, randomI, 0);
  strip.show();
    delay(50);
  break;
  case 3:
  strip.setPixelColor(pNum, 0, 0, randomI);
  strip.show();
    delay(50);
  break;
  case 4:
  strip.setPixelColor(pNum, randomI, randomI, randomI);
  strip.show();
    delay(50);
  default:
  strip.setPixelColor(pNum, 255,255,255);
  strip.show();
    delay(50);
  break;
  }
  randomP = random(1, 4);
  randomI = random(32, 256);
  }
  strip.clear();
}


void randomSmoothLightup(){
   long randomI = random(32, 256);
   long randomP = random(1, 5);
  for(int pNum = 0; pNum <= 59; pNum++){
  switch(randomP){
  case 1:
    strip.setPixelColor(pNum, randomI, 0, 0);
    strip.show();
    delay(50);
    break;
  case 2:
  strip.setPixelColor(pNum, 0, randomI, 0);
  strip.show();
    delay(50);
  break;
  case 3:
  strip.setPixelColor(pNum, 0, 0, randomI);
  strip.show();
    delay(50);
  break;
  case 4:
  strip.setPixelColor(pNum, randomI, randomI, randomI);
  strip.show();
    delay(50);
  default:
  strip.setPixelColor(pNum, 255,255,255);
  strip.show();
    delay(50);
  break;
  }
  randomP = random(1, 4);
  randomI = random(32, 256);
  }
  strip.clear();
}
void randomBlink(){
  long randomIntensity = random(32, 256);
  long randomPixel = random(1, 5);
  Serial.println(randomPixel);
  for(int pNumber = 0; pNumber <= 59; pNumber++){
  switch(randomPixel){
  case 1:
    strip.setPixelColor(pNumber, randomIntensity, 0, 0);
    break;
  case 2:
  strip.setPixelColor(pNumber, 0, randomIntensity, 0);
  break;
  case 3:
  strip.setPixelColor(pNumber, 0, 0, randomIntensity);
  break;
  case 4:
  strip.setPixelColor(pNumber, randomIntensity, randomIntensity, randomIntensity);
  break;
  default:
  strip.setPixelColor(pNumber, 255,255,255);
  break;
  }
  randomPixel = random(1, 4);
  }
  strip.show();
  delay(300);
  strip.clear();
}


void smoothLightupBackwards(){
   strip.clear();
  pixels = 59;
  while(pixels <= 59){
  if (pixels%5 == 0){
 strip.setPixelColor(pixels, 0, 0, 255);
strip.show();
 delay(50);
  }
 else if (pixels%2 == 0){
  strip.setPixelColor(pixels, 255, 0, 0);
  strip.show();
 delay(50);
 }
 else{
  strip.setPixelColor(pixels, 0, 255, 0);
  strip.show();
  delay(50);
 }
 pixels--;
}
}


void pixelBlinkRedGreen(int timeBetween,int numberofTimes ){
  pixels = 0;
  int i = 0;
  while (i < numberofTimes){
  strip.clear();
  strip.show();
  delay(timeBetween);
  pixels = 0;
  while(pixels <= 59){
    if (pixels%2 == 0){
 strip.setPixelColor(pixels, 0, 255,0);
  }
 else{
  strip.setPixelColor(pixels, 255, 0, 0);
 }
 pixels++;
  }
   strip.show();
   delay(timeBetween);
  strip.clear();
    delay(timeBetween);
    strip.show();
    i++;
    pixels = 0;
  }
}


void smoothLightup(){
  strip.clear();
  
  while(pixels <= 59){
  if (pixels%5 == 0){
 strip.setPixelColor(pixels, 0, 0, 255);
strip.show();
 delay(50);
  }
 else if (pixels%2 == 0){
  strip.setPixelColor(pixels, 255, 0, 0);
  strip.show();
 delay(50);
 }
 else{
  strip.setPixelColor(pixels, 0, 255, 0);
  strip.show();
  delay(50);
 }
 pixels++;
}
}


