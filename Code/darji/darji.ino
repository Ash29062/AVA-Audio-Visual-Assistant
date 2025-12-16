


#include <Adafruit_NeoPixel.h>

#define LED_PIN1   15

#define LED_PIN2    0
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 500

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN2, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------











// 1 sec, 2 sec, 45 sec, 60 sec and 5 mins.
 float timeArray[] = {8, 8.5, 9.5,10,15,17,21.32,21.64,25,25.5,27.5,29,34,37.3,40,40.5,41,41.5,47.4,51.4,52.5,53,57,73,74,74.5,77,88,90,93,94,94.5,98,98.5,103,103.5,107,129,132,134,137};

int gloves[][3]  = { {128,128,128},{0,0,0},{85,170,85},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,127},{0,0,0},{0,127,127},{0,0,0},{64,0,192},{0,0,0},{153,85,64},{0,0,0},{110,51,102},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{153,85,64},{0,0,0},{0,0,255},{0,0,0},{153,85,64} };
int jacket[][3]  = { {128,128,128},{0,0,0},{85,170,85},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,127},{0,0,0},{0,127,127},{0,0,0},{64,0,192},{0,0,0},{153,85,64},{0,0,0},{110,51,102},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{153,85,64},{0,0,0},{0,0,255},{0,0,0},{153,85,64} };
int hat[][3]     = { {128,128,128},{0,0,0},{85,170,85},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,127},{0,0,0},{0,127,127},{0,0,0},{64,0,192},{0,0,0},{153,85,64},{0,0,0},{110,51,102},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{153,85,64},{0,0,0},{0,0,255},{0,0,0},{153,85,64} };
int pant[][3]    = { {128,128,128},{0,0,0},{85,170,85},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,127},{0,0,0},{0,127,127},{0,0,0},{64,0,192},{0,0,0},{153,85,64},{0,0,0},{110,51,102},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{128,128,128},{0,0,0},{102,51,77},{0,0,0},{85,85,85},{0,0,0},{153,85,64},{0,0,0},{0,0,255},{0,0,0},{153,85,64} };

int arrayIndex = 0;

void setup()
{
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
 
 strip2.begin();
 strip2.show();
 strip2.setBrightness(50);
Serial.begin(9600);
}
void loop(){
 int currentTime = millis();
  if (currentTime >= (timeArray[arrayIndex]*1000)){
  Serial.print("Time elapsed (sec) = ");
  Serial.println (timeArray[arrayIndex]);


  // Hat,Jacket,Glove
  colorWipe(strip.Color( jacket[arrayIndex][0],jacket[arrayIndex][1],jacket[arrayIndex][2])); 
  colorWipe2(strip.Color( jacket[arrayIndex][0],jacket[arrayIndex][1],jacket[arrayIndex][2])); 
  // colorWipe(strip.Color(  , 0,   0), 1); 
  // colorWipe(strip.Color(  0, 0,   0), 1); 

  // colorWipe(strip.Color(  0, 0,   0), 1); 

  arrayIndex = arrayIndex +1;
   
  }
}

void colorWipe(uint32_t color) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip.show();    
}


void colorWipe2(uint32_t color) {
  for(int i=0; i<strip2.numPixels(); i++) { // For each pixel in strip...
    strip2.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip2.show();    
}