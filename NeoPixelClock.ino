#include <Adafruit_NeoPixel.h>
#include <ColorFunctions.ino>
#include <ButtonControls.ino>
#include <ClockFace.ino>

#define PIN 10          // NeoPixel data pin
float brightness = 0.20; // must be less than 1

#define buttonSelect 12  
#define buttonUp 1      // TX on Flora
#define buttonDown 0    // RX on Flora
#define buttonLeft 2    // SDA on Flora
#define buttonRight 3   // SCL on Flora  

int buttons[] = {buttonSelect, buttonUp, buttonDown, buttonLeft, buttonRight};
int buttonStates[] = {LOW, LOW, LOW, LOW, LOW};
int buttonCount = 5;

int buttonState0;
int lastButtonState0 = HIGH;
long lastDebounceTime0 = 0;

int buttonState1;
int lastButtonState1 = HIGH;
long lastDebounceTime1 = 0;

int buttonState2;
int lastButtonState2 = HIGH;
long lastDebounceTime2 = 0;

int buttonState3;
int lastButtonState3 = HIGH;
long lastDebounceTime3 = 0;

int buttonState4;
int lastButtonState4 = HIGH;
long lastDebounceTime4 = 0;

int buttonMetas[5][3] = {
  { buttonState0, lastButtonState0, lastDebounceTime0 },
  { buttonState1, lastButtonState1, lastDebounceTime1 },
  { buttonState2, lastButtonState2, lastDebounceTime2 },
  { buttonState3, lastButtonState3, lastDebounceTime3 },
  { buttonState4, lastButtonState4, lastDebounceTime4 }
};

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(buttonSelect, INPUT_PULLUP);
  pinMode(buttonUp,     INPUT_PULLUP);
  pinMode(buttonDown,   INPUT_PULLUP);
  pinMode(buttonLeft,   INPUT_PULLUP);
  pinMode(buttonRight,  INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(brightness * 255);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int thisButton = 0; thisButton < buttonCount; thisButton++) {
    buttonStates[thisButton] = readButton(buttons[thisButton], buttonMetas[thisButton]);
  }
      if (buttonStates[0] == LOW) {
        colorWipe(strip.Color(255, 100, 0), 10); // ORANGE
      }
      else if (buttonStates[1] == LOW) {
        colorWipe(strip.Color(0, 255, 0), 10); // Green
      }
      else if (buttonStates[2] == LOW) {
        colorWipe(strip.Color(0, 0, 255), 10); // Blue
      }
      else if (buttonStates[3] == LOW) {
        colorWipe(strip.Color(125, 0, 125), 10); // magenta
      }
      else if (buttonStates[4] == LOW) {
        colorWipe(strip.Color(125, 125, 125), 10); // white
      }

  // // Some example procedures showing how to display to the pixels:
  // colorWipe(strip.Color(255, 0, 0), 50); // Red
  // colorWipe(strip.Color(0, 255, 0), 50); // Green
  // colorWipe(strip.Color(0, 0, 255), 50); // Blue
  // rainbow(20);
  // rainbowCycle(20);
}



