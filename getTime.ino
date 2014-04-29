#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

tmElements_t getTime() {
  tmElements_t time;
  
  if (RTC.read(time)) {
    return(time);
  } 
}
