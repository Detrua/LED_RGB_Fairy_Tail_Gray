

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

const int LED_SOLO_PIN = 3;
const int LED_SOLO_BRIGHTNESS = 10;


#define LED_PIN 2
#define LED_COUNT 78


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



// setup() function -- runs once at startup --------------------------------

void setup() {
  pinMode( LED_PIN, OUTPUT );
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(20); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...
  analogWrite( LED_SOLO_PIN, LED_SOLO_BRIGHTNESS );
  colorWipe(strip.Color(125, 255, 255), 40); // Red
  colorWipe(strip.Color(125, 160, 255), 40); // Green



}


// Some functions of our own for creating animated effects -----------------


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
