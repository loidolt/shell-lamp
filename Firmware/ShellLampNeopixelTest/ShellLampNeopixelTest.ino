#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            1  // Which pin on the Arduino is connected to the NeoPixels?

#define NUMPIXELS      7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

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

  strip.begin(); // This initializes the NeoPixel library.

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

 for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }

}

