// From the debounce example sketch. 
// Turned into a function with dependency injection
// to make it easier to use in the loop for numerous buttons
// Note that this is set up for buttons attached to a pull-up
// not pull-down.

int readButton(int button, int buttonMeta[3]) {

  //long lastDebounceTime = 0;  // the last time the output pin was toggled
  long debounceDelay = 50;    // the debounce time; increase if the output flickers

  int reading = digitalRead(button);
  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading !=  buttonMeta[1]) { //lastButtonState) {
    // reset the debouncing timer
    buttonMeta[2] = millis(); //lastDebounceTime = millis();
  } 
  
  if ((millis() - buttonMeta[2]) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonMeta[0]) {//buttonState) {
      buttonMeta[0] = reading;

       // only toggle the LED if the new button state is HIGH
      if (buttonMeta[0] == LOW) {
        return LOW;
      }
    }
  }
  // if button not really pressed return default state;
  return HIGH;
}