// #include <Time.h>

// int lastMin = 16;
// int lastHour = 16;
// int startLED = 0;
// int startLEDlast = 16;
// int lastCombined = 0;
// int start = 0;

// void setup() {
// uint32_t Timer = millis();

// }

// void loop() {
//  if (start == 0) {
//   // set the Time to the latest GPS reading
//   setTime(startUpHour, startUpMinute, startUpSeconds, startUpDay, startUpMonth, startUpYear);
//   delay(50);
//   adjustTime(offset * SECS_PER_HOUR);
//   delay(500);
//   tripDistance = (double)calc_dist(fLat, fLon, targetLat, targetLon);
//   start = 1;
//   }



// }

// void clockMode() {
// if (start == 1) {
//     strip.setPixelColor(startLEDlast, strip.Color(0, 0, 0));
//     strip.show();
    
//     float gpsMin = (minute() + (second()/60.0));
//     unsigned int ledMin = 0;
//     int minTemp = 0;
//     if (gpsMin <= 1.875) minTemp = topLED;
//     if ((gpsMin > 1.875) && (gpsMin <= 5.625)) minTemp = topLED - 1;
//     if ((gpsMin > 5.625) && (gpsMin <= 9.375)) minTemp = topLED - 2;
//     if ((gpsMin > 9.375) && (gpsMin <= 13.125)) minTemp = topLED - 3;
//     if ((gpsMin > 13.125) && (gpsMin <= 16.875)) minTemp = topLED - 4;
//     if ((gpsMin > 16.875) && (gpsMin <= 20.625)) minTemp = topLED - 5;
//     if ((gpsMin > 20.625) && (gpsMin <= 24.375)) minTemp = topLED - 6;
//     if ((gpsMin > 24.375) && (gpsMin <= 28.125)) minTemp = topLED - 7;
//     if ((gpsMin > 28.125) && (gpsMin <= 31.875)) minTemp = topLED - 8;
//     if ((gpsMin > 31.875) && (gpsMin <= 35.625)) minTemp = topLED - 9;
//     if ((gpsMin > 35.625) && (gpsMin <= 39.375)) minTemp = topLED - 10;
//     if ((gpsMin > 39.375) && (gpsMin <= 43.125)) minTemp = topLED - 11;
//     if ((gpsMin > 43.125) && (gpsMin <= 46.875)) minTemp = topLED - 12;
//     if ((gpsMin > 46.875) && (gpsMin <= 50.625)) minTemp = topLED - 13;
//     if ((gpsMin > 50.625) && (gpsMin <= 54.375)) minTemp = topLED - 14;
//     if ((gpsMin > 54.375) && (gpsMin <= 58.125)) minTemp = topLED - 15;
//     if (gpsMin > 58.125) minTemp = topLED - 16;
    
//     if (minTemp < 0) {
//       ledMin = minTemp + 16;
//     } else {
//       ledMin = minTemp;
//     }
    
//     float gpsHour = (hour() + (minute()/60.0));
//     if (gpsHour > 12) { gpsHour = gpsHour - 12; }
//     unsigned int ledHour = 0;
//     int hourTemp = 0;
//     if (gpsHour <= 0.375) hourTemp = topLED;
//     if ((gpsHour > 0.375) && (gpsHour <= 1.125)) hourTemp = topLED - 1;
//     if ((gpsHour > 1.125) && (gpsHour <= 1.875)) hourTemp = topLED - 2;
//     if ((gpsHour > 1.875) && (gpsHour <= 2.625)) hourTemp = topLED - 3;
//     if ((gpsHour > 2.625) && (gpsHour <= 3.375)) hourTemp = topLED - 4;
//     if ((gpsHour > 3.375) && (gpsHour <= 4.125)) hourTemp = topLED - 5;
//     if ((gpsHour > 4.125) && (gpsHour <= 4.875)) hourTemp = topLED - 6;
//     if ((gpsHour > 4.875) && (gpsHour <= 5.625)) hourTemp = topLED - 7;
//     if ((gpsHour > 5.625) && (gpsHour <= 6.375)) hourTemp = topLED - 8;
//     if ((gpsHour > 6.375) && (gpsHour <= 7.125)) hourTemp = topLED - 9;
//     if ((gpsHour > 7.125) && (gpsHour <= 7.875)) hourTemp = topLED - 10;
//     if ((gpsHour > 7.875) && (gpsHour <= 8.625)) hourTemp = topLED - 11;
//     if ((gpsHour > 8.625) && (gpsHour <= 9.375)) hourTemp = topLED - 12;
//     if ((gpsHour > 9.375) && (gpsHour <= 10.125)) hourTemp = topLED - 13;
//     if ((gpsHour > 10.125) && (gpsHour <= 10.875)) hourTemp = topLED - 14;
//     if ((gpsHour > 10.875) && (gpsHour <= 11.625)) hourTemp = topLED - 15;
//     if (gpsHour > 11.625) hourTemp = topLED - 16;
    
//     if (hourTemp < 0) {
//       ledHour = hourTemp + 16;
//     } else {
//       ledHour = hourTemp;
//     }

//     if ((ledHour == ledMin) && (lastCombined == 0)) {
//       strip.setPixelColor(lastHour, strip.Color(0, 0, 0));
//       strip.setPixelColor(lastMin, strip.Color(0, 0, 0));
//       strip.setPixelColor(ledHour, strip.Color(255, 0, 255));
//       strip.show();
//       lastCombined = 1;
//       lastHour = ledHour;
//       lastMin = ledMin;
//     } else {
//       if (lastHour != ledHour) {
//         strip.setPixelColor(lastHour, strip.Color(0, 0, 0));
//         strip.setPixelColor(ledHour, strip.Color(255, 50, 0));
//         strip.show();
//         lastHour = ledHour;
//       }
//       if (lastMin != ledMin) {
//         strip.setPixelColor(lastMin, strip.Color(0, 0, 0));
//         strip.setPixelColor(ledMin, strip.Color(200, 200, 0));
//         if (lastCombined == 1) {
//           strip.setPixelColor(ledHour, strip.Color(255, 0, 0));
//           lastCombined = 0;
//         }
//         strip.show();
//         lastMin = ledMin;
//       }
//     }   
//   } else {
//     // if millis() or timer wraps around, we'll just reset it
//     if (startupTimer > millis()) startupTimer = millis();
      
//     // approximately every 10 seconds or so, update time
//     if (millis() - startupTimer > 200) {
//       startupTimer = millis(); // reset the timer
//       if (startLED == 16) {
//         startLED = 0;
//       }
//       strip.setPixelColor(startLEDlast, strip.Color(0, 0, 0));
//       strip.setPixelColor(startLED, strip.Color(0, 255, 0));
//       strip.show();
//       startLEDlast = startLED;
//       startLED++;
//       //delay(200);
//     }
//   }
// }
