int one       = topLED + 2;
int two       = topLED + 4;
int three     = topLED + 6;
int four      = topLED + 8;
int five      = topLED + 10;
int six       = topLED + 12;
int seven     = topLED + 14;
int eight     = topLED + 16;
int nine      = topLED + 18;
int ten       = topLED + 20;
int eleven    = topLED + 22;
int twelve    = topLED;

 // from Adafruit's NeoGeo Watch code. Changed to work with RTC instead of GPS. Possibly slightly modified in other ways.
 
int startLEDlast;
int lastCombined = 0;
int lastHour     = 0;
int lastMin      = 0;

 void updateClock(tmElements_t time) {
     strip.setPixelColor(startLEDlast, strip.Color(0, 0, 0));
     strip.show();
    
//     float gpsMin = (minute() + (second()/60.0));
     unsigned int ledMin = 0;
     int minTemp = 0;
     minTemp = topLED - (int)((time.Minute * 60 + time.Second) / 150);
     
     if (minTemp < 0) {
       ledMin = minTemp + 16;
     } else {
       ledMin = minTemp;
     }
    
     float rtcHour = (time.Hour);
     if (rtcHour > 12) { rtcHour = rtcHour - 12; }
     unsigned int ledHour = 0;
     int hourTemp = 0;
     hourTemp = topLED - (rtcHour * 2);

     if (hourTemp < 0) {
       ledHour = hourTemp + 16;
     } else {
       ledHour = hourTemp;
     }

     if ((ledHour == ledMin) && (lastCombined == 0)) {
       strip.setPixelColor(lastHour, strip.Color(0, 0, 0));
       strip.setPixelColor(lastMin, strip.Color(0, 0, 0));
       strip.setPixelColor(ledHour, strip.Color(255, 0, 255));
       strip.show();
       lastCombined = 1;
       lastHour = ledHour;
       lastMin = ledMin;
     } else {
       if (lastHour != ledHour) {
         strip.setPixelColor(lastHour, strip.Color(0, 0, 0));
         strip.setPixelColor(ledHour, strip.Color(255, 50, 0));
         strip.show();
         lastHour = ledHour;
       }
       if (lastMin != ledMin) {
         strip.setPixelColor(lastMin, strip.Color(0, 0, 0));
         strip.setPixelColor(ledMin, strip.Color(200, 200, 0));
         if (lastCombined == 1) {
           strip.setPixelColor(ledHour, strip.Color(255, 0, 0));
           lastCombined = 0;
         }
         strip.show();
         lastMin = ledMin;
       }
     }   
   }

