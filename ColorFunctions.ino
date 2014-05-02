// function wrapper to allow setting of brightness by pixel.

void setPixelColorBrightness(int pixel, int r, int g, int b, float brightness) {
  strip.setPixelColor(pixel, strip.Color((int)(r * brightness), (int)(g * brightness), (int)(b * brightness)));  
}

void fadePixelUp(int pixel, int r, int g, int b, float brightness) {
  int fadeRate = 2; // effectively millis of delay() between fade steps
  int fadeSteps = 50;
  for (float i = 0.0; i < brightness; i += (brightness / fadeSteps)) {
    setPixelColorBrightness(pixel, r, g, b, i);
    strip.show();
    delay(fadeRate);
  }
}

void fadePixelDown(int pixel, int r, int g, int b, float brightness) {
  int fadeRate = 2; // effectively millis of delay() between fade steps
  int fadeSteps = 50;
  for (float i = brightness; i > 0.0; i -= (brightness / fadeSteps)) {
    setPixelColorBrightness(pixel, r, g, b, i);
    strip.show();
    delay(fadeRate);
  }
}

// Not used in project. These will probably be deleted eventually. 
// From the Adafruit NeoPixel strandtest sketch

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
