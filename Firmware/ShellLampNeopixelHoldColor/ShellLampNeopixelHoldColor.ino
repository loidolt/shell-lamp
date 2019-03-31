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

int redBright;
int greenBright;
int blueBright;

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

}

void loop() {

 potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    potVal = (potVal * 3) / 4; // Normalize to 0-255

    red = 256 - potVal;  // Red from full to off
    green = potVal;        // Green from off to full
    blue = 1;             // Blue off
  }
  else if (potVal < 682) // Middle third of potentiometer's range (341-681)
  {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255

    red = 1;            // Red off
    green = 256 - potVal; // Green from full to off
    blue = potVal;       // Blue from off to full
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    potVal = ( (potVal-683) * 3) / 4; // Normalize to 0-255

    red = potVal;       // Red from off to full
    green = 1;            // Green off
    blue = 256 - potVal; // Blue from full to off
  }

  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(red, green, blue));

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }

}

void light(){

  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  potVal = (( (potVal-683) * 3) / 4) / 255; // Normalize to 0-255

  redBright = red * potVal;
  greenBright = blue * potVal;
  blueBright = blue * potVal;
  
  
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(redBright, greenBright, blueBright));

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  
}


void color(){

  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    potVal = (potVal * 3) / 4; // Normalize to 0-255

    red = 256 - potVal;  // Red from full to off
    green = potVal;        // Green from off to full
    blue = 1;             // Blue off
  }
  else if (potVal < 682) // Middle third of potentiometer's range (341-681)
  {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255

    red = 1;            // Red off
    green = 256 - potVal; // Green from full to off
    blue = potVal;       // Blue from off to full
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    potVal = ( (potVal-683) * 3) / 4; // Normalize to 0-255

    red = potVal;       // Red from off to full
    green = 1;            // Green off
    blue = 256 - potVal; // Blue from full to off
  }

  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(red, green, blue));

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  
}


