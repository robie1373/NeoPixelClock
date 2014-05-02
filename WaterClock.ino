int lastWaterHour = -1;
int lastFifthMin = 0;
int lastWaterMin     = 0;
int fifthMin    = 0;
int rtcHour     = 0;
//int bottomMin  = bottomHour() - 1;
int topMin     = topLED;
int dripDelay = 300;

int start = 0;

// Configuration functions
int bottomHour() {
  return(topLED + 12);  
}

int bottomMin() {
 return(bottomHour() - 1); 
}

int topHour() {
  int tHour = topLED - 2;
 if (tHour < 0) { tHour = tHour + 24; } 
 return(tHour);
}

float hourBrightness() { return(0.5); }
float minuteBrightness() { return(0.3); }

// Begin the functions that do things!
void updateWaterClock(tmElements_t time) {
//  strip.setPixelColor(bottomHour(), strip.Color(255,0,0)); // red
//  strip.setPixelColor(bottomMin(), strip.Color(255,0,0)); // red
  if (time.Hour > 12) {
    rtcHour = time.Hour - 12;
  } else {
    rtcHour = time.Hour;
  }
//    printTime(time); // DEBUG
  int thisMin = time.Minute;
  // update fifthMin every 5 minutes. This is when we want to add an LED to display
  fifthMin = (int)(time.Minute / 5);
  if (fifthMin < 0) { fifthMin = fifthMin + 12; }
  
  if (start == 0) { 
    startUp(rtcHour, fifthMin);
    start = 1;
   }
  
  if (rtcHour != lastWaterHour) {
  fillHours(rtcHour);
  lastWaterHour = rtcHour;
  }
 
  if (fifthMin != lastFifthMin) {
    fillMins(fifthMin);
    lastWaterMin = thisMin;
  } else if (thisMin != lastWaterMin) {
     dripMin(fifthMin - 1);
    lastWaterMin = thisMin; 
  }
  lastFifthMin = fifthMin;
}

void startUp(int waterHour, int waterMin) {
  for (int i = 0; i <= 12; i++) {
     if (i < waterHour) {
       int thisHour = (bottomHour() + i);
       dripHour(i);
       setHourPixel(thisHour);
     }
    
    if (i < waterMin) {
     dripMin(i);
     setMinPixel(bottomMin() - i);
    } 
    lastFifthMin = waterMin;
  }
}

void fillHours(int waterHour) {
  if (waterHour % 12 == 0) {
  blankHours();
  } else {
    int thisHour = (bottomHour() + waterHour - 1);
    // add waterHour because this side is filling clockwise
    dripHour(waterHour);
    setHourPixel(thisHour);
  }
}

void fillMins(int waterMin) {
  if (waterMin % 60 == 0) {
   blankMins(); 
  } else {
    int thisMin = bottomMin() - waterMin + 1;
    // subtract waterMin because this side is filling counter clockwise
    dripMin(waterMin);
    setMinPixel(thisMin);
  }
}

void dripHour(int dHour) {
  delay(275);
  //  dHour = rationalizeHour(dHour);
 for (int i = topHour(); i > (bottomHour() + dHour); i--) {
  setHourPixel(i);
  strip.show();
  delay(dripDelay);
  clearPixel(i);
  strip.show();
 } 
}

void dripMin(int dMin) {
  delay(275);
  for (int i = topMin; i < (bottomMin() - dMin); i++) {
    setMinPixel(i);
    strip.show();
    delay(dripDelay);
    clearPixel(i);
    strip.show(); 
  }
}

void blankHours() {
  for (int i = topHour(); i >= bottomHour(); i--) {
    fadePixelDown(i, 255, 0, 255, hourBrightness());
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
    delay(dripDelay);
  }
}

void blankMins() {
  for (int i = topMin; i <= bottomMin(); i++) {
    fadePixelDown(i, 255, 255, 255, minuteBrightness());
    strip.setPixelColor(i, strip.Color(0,0,0)); 
    strip.show();
  }
  delay(dripDelay);
}

// These might be useful for balancing the speed at which
// hour and minute fade.
//float hmBrightnessRatio( float hbright, float mbright) {
//  return(hbright / mbright);  
//}
//float mhBrightnessRatio( float hbright, float mbright) {
//  return(mbright / hbright);  
//}

void setHourPixel(int pixel) {
//  strip.setPixelColor(pixel, strip.Color(125,0,125)); // Magenta
  fadePixelUp(pixel, 255, 0, 255, hourBrightness());
  delay(dripDelay);
  setPixelColorBrightness(pixel, 255, 0, 255, hourBrightness());
  strip.show();
}

void setMinPixel(int pixel) {
//  strip.setPixelColor(pixel, strip.Color(125,125,125)); // White
  fadePixelUp(pixel, 255, 255, 255, minuteBrightness());
  delay(dripDelay);
  setPixelColorBrightness(pixel, 255, 255, 255, minuteBrightness());
  strip.show();
}

void clearPixel(int pixel) {
  strip.setPixelColor(pixel, strip.Color(0,0,0)); 
  strip.show();
}

// This might need to be used if you set topLED to something else.
//int rationalizeHour(int inHour) {
//  int outHour;
// if (inHour > 23) { outHour = inHour - 12; } 
// else if (inHour < 0) { outHour = inHour +12; }
// return(outHour);
//}


void printTime(tmElements_t time) {
  Serial.print("Time: ");
  Serial.print(time.Hour);
  Serial.print(":");
  Serial.print(time.Minute);
  Serial.print(".");
  Serial.println(time.Second);
}
