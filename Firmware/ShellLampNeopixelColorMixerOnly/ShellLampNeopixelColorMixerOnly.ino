#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            1  // Which pin on the Arduino is connected to the NeoPixels?

#define NUMPIXELS      7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

int button = 4;
int latch_state;
int button_delay;

int potPin = 3;
int potVal = 0;

int red;
int green;
int blue;

int switchCase;

void setup() {

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

  button_delay = 0;
  latch_state = 0;

  pinMode(button, INPUT_PULLUP);
  pinMode(potPin, INPUT_PULLUP);

  int red = 0;
  int green = 0;
  int blue = 0;

  int switchCase = 0;

}

void loop() {

 potVal = analogRead(potPin) / 4;   // read the potentiometer value at the input pin

   if (potVal > 0 && potVal < 100){
    switchCase = 0;
  }
      else if (potVal >= 100 && potVal < 115){
        switchCase = 1;
      }
      else if (potVal >= 115 && potVal < 135){
        switchCase = 2;
      }
      else if (potVal >= 135 && potVal < 150){
        switchCase = 3;
      }
      else if (potVal >= 150 && potVal < 165){
        switchCase = 4;
      }
      else if (potVal >= 165 && potVal < 180){
        switchCase = 5;
      }
      else if (potVal >= 195 && potVal < 210){
        switchCase = 6;
      }
      else if (potVal >= 210 && potVal < 225){
        switchCase = 7;
      }
      else if (potVal >= 225 && potVal < 240){
        switchCase = 8;
      }
      else {
        switchCase = 9;
      }
 
switch(switchCase){
  case 0:
    red = 0;
    green = 0;
    blue = 0;
    break;
  case 1:
    red = 255;
    green = 0;
    blue = 0;
    break; 
  case 2:
    red = 0;
    green = 255;
    blue = 0;
    break;
  case 4:
    red = 255;
    green = 147;
    blue = 41;
    break;
  case 5:
    red = 0;
    green = 0;
    blue = 255;
    break;
  case 6:
    red = 255;
    green = 0;
    blue = 255;
    break;
  case 7:
    red = 0;
    green = 0;
    blue = 255;
    break;
  case 8:
    red = 255;
    green = 255;
    blue = 255;
    break;       
}


  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(red, green, blue));

    pixels.show(); // This sends the updated pixel color to the hardware.

  }

}

