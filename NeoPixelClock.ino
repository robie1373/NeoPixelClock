#include <Adafruit_NeoPixel.h>
#include <ColorFunctions.ino>
#include <ButtonControls.ino>
#include <ClockFace.ino>
#include <checkButtons.ino>
#include <WaterClock.ino>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

/////////////////////////
//
// Version 0.0.1
//
////////////////////////

#define NEODATAPIN 10          // NeoPixel data pin
float brightness = 0.20; // must be less than 1

#define buttonUp 12  
#define buttonRight 1     // TX on Flora
#define buttonDown 0      // RX on Flora
#define buttonSelect 6    
#define buttonLeft 9      

// For RTC
#define SDA 2             // SDA on Flora
#define SCL 3             // SCL on Flora

int buttonSelectState = LOW;
int buttonUpState     = LOW;
int buttonDownState   = LOW;
int buttonLeftState   = LOW;
int buttonRightState  = LOW;

int buttons[]       = {buttonSelect,      buttonUp,       buttonDown,      buttonLeft,      buttonRight};
int buttonStates[]  = {buttonSelectState, buttonUpState,  buttonDownState, buttonLeftState, buttonRightState};
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

// Neopixel code from Adafruit examples, obviously.
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, NEODATAPIN, NEO_GRB + NEO_KHZ800);
//  Set topLED to be the top LED on your ring. (numbers go counter clockwise, I think)
#define topLED 1

void setup() {
  Serial.begin(115200);
  pinMode(buttonSelect, INPUT_PULLUP);
  pinMode(buttonUp,     INPUT_PULLUP);
  pinMode(buttonDown,   INPUT_PULLUP);
  pinMode(buttonLeft,   INPUT_PULLUP);
  pinMode(buttonRight,  INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(brightness * 255);
  strip.show(); // Initialize all pixels to 'off'
  delay(500);
  
  //////////////////////
  //
  // DEBUGGERY
  //
  //////////////////////
//  strip.setPixelColor(topLED, strip.Color(0,255,0)); // green
//  strip.setPixelColor(0, strip.Color(125,125,125)); // white

}

void loop() {
  // set the Time to the latest RTC reading
  tmElements_t time = getTime();
  updateWaterClock(time);
  checkButtons(time);

  // Just a little rate limiting. There are some other delays in the waterclock code, but 
  // between display changes I don't think you hit any of them. This app is very much not
  // real time, so my hope is this provides a little bit of power savings.
  delay(100);
}

