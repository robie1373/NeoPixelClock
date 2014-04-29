
void checkButtons(tmElements_t time) {
    for (int thisButton = 0; thisButton < buttonCount; thisButton++) {
    buttonStates[thisButton] = readButton(buttons[thisButton], buttonMetas[thisButton]);
  }
  if (buttonStates[0] == LOW) {
    colorWipe(strip.Color(255, 100, 0), 10); // ORANGE
  }
  else if (buttonStates[1] == LOW) {
//    colorWipe(strip.Color(0, 255, 0), 10); // Green
  updateWaterClock(time);
  }
  else if (buttonStates[2] == LOW) {
    colorWipe(strip.Color(0, 0, 255), 10); // Blue
  }
  else if (buttonStates[3] == LOW) {
    colorWipe(strip.Color(125, 0, 125), 10); // magenta
  }
  else if (buttonStates[4] == LOW) {
    colorWipe(strip.Color(85, 85, 85), 10); // white
  }
}
