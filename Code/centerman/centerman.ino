

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
 float timeArray[] = {7, 8, 9.5,16,17.5,20,21.16,21.80,21.96,22,27.5,29,34,38,38.5,42.5,52,53.3,54,55,55.5,57,73,73.6,77,92,96,97,98,102,102.5,107,129,132,134,137,142,146};

int gloves[][3]  = { {0,255,0},{0,0,0},{85,170,85},{0,0,0},{0,255,0},{0,0,0},{76,85,43},{0,0,0},{0,127,0},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,0},{0,0,0},{64,127,64},{0,0,0},{64,127,64},{0,0,0},{0,255,0},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{85,170,51},{0,0,0},{0,127,0},{0,0,0},{0,127,0},{0,0,0},{153,85,64},{0,0,0} };
int jacket[][3]  = { {0,255,0},{0,0,0},{85,170,85},{0,0,0},{0,255,0},{0,0,0},{76,85,43},{0,0,0},{0,127,0},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,0},{0,0,0},{64,127,64},{0,0,0},{64,127,64},{0,0,0},{0,255,0},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{85,170,51},{0,0,0},{0,127,0},{0,0,0},{0,127,0},{0,0,0},{153,85,64},{0,0,0} };
int hat[][3]     = { {0,255,0},{0,0,0},{85,170,85},{0,0,0},{0,255,0},{0,0,0},{76,85,43},{0,0,0},{0,127,0},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,0},{0,0,0},{64,127,64},{0,0,0},{64,127,64},{0,0,0},{0,255,0},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{85,170,51},{0,0,0},{0,127,0},{0,0,0},{0,127,0},{0,0,0},{153,85,64},{0,0,0} };
int pant[][3]    = { {0,255,0},{0,0,0},{85,170,85},{0,0,0},{0,255,0},{0,0,0},{76,85,43},{0,0,0},{0,127,0},{0,0,0},{0,127,127},{0,0,0},{102,51,77},{0,0,0},{0,127,0},{0,0,0},{64,127,64},{0,0,0},{64,127,64},{0,0,0},{0,255,0},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{0,255,0},{0,0,0},{102,51,77},{0,0,0},{85,170,51},{0,0,0},{0,127,0},{0,0,0},{0,127,0},{0,0,0},{153,85,64},{0,0,0} };

int arrayIndex = 0;

void setup()
{
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
 
 strip2.begin();
 strip2.show();
 strip2.setBrightness(30);
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