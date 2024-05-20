#include <FastLED.h>

#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 30
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

const int buttonPins[7] = { 5, 6, 7, 8, 9, 10, 11 };
int buttonState[7] = { 0, 0, 0, 0, 0, 0, 0 };

int fadeAmount = 5;

void setup() {
  Serial.begin(9600);

  FastLED.addLeds<WS2813, 4>(leds[0], NUM_LEDS_PER_STRIP);  // 0 -> blue
  FastLED.addLeds<WS2813, 2>(leds[1], NUM_LEDS_PER_STRIP);  // 1 -> yellow
  FastLED.addLeds<WS2813, 3>(leds[2], NUM_LEDS_PER_STRIP);  // 2 -> red

  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void name(int brightness) {
  leds[0][28] = CRGB(brightness, brightness, brightness);
  leds[0][29] = CRGB(brightness, brightness, brightness);
}

void religion(int brightness) {
  leds[0][22] = CRGB(brightness, brightness, brightness);
  leds[0][23] = CRGB(brightness, brightness, brightness);
  leds[0][24] = CRGB(brightness, brightness, brightness);

  leds[0][16] = CRGB(brightness, brightness, brightness);
  leds[0][17] = CRGB(brightness, brightness, brightness);
  leds[0][18] = CRGB(brightness, brightness, brightness);
}

void people(int brightness) {
  leds[1][0] = CRGB(brightness, brightness, brightness);
}

void kids(int brightness) {
  leds[1][29] = CRGB(brightness, brightness, brightness);
}

void house(int brightness) {
  // This inner loop will go over each led in the current strip, one at a time
  for (int i = 0; i < 9; i++) {
    leds[0][i] = CRGB(brightness, brightness, brightness);
  }
}

void lamp(int brightness) {
  leds[1][26] = CRGB(brightness, brightness, brightness);
  leds[2][8] = CRGB(brightness, brightness, brightness);
}

void space(int brightness) {
  leds[2][12] = CRGB(brightness, brightness, brightness);
  leds[2][13] = CRGB(brightness, brightness, brightness);
  leds[2][14] = CRGB(brightness, brightness, brightness);

  leds[2][17] = CRGB(brightness, brightness, brightness);
  leds[2][18] = CRGB(brightness, brightness, brightness);
  leds[2][19] = CRGB(brightness, brightness, brightness);
}

void road(int brightness) {
  for (int i = 18; i < 24; i++) {
    leds[1][i] = CRGB(brightness, brightness, brightness);
  }
}

void canal(int brightness) {
  for (int i = 10; i < 16; i++) {
    leds[1][i] = CRGB(brightness, brightness, brightness);
  }
}

void rubbish(int brightness) {
  leds[1][6] = CRGB(brightness, brightness, brightness);
}



long mapBrightness(int value) {
  if (value > 40) {
    return 255;
  } else {
    // double number = map(sqrt(value), 0, 40, 0, 255);
    // double number = 40*sq(value/40.00);
    // number = map(number, 0, 40, 0, 255);
    // if (number != 0) {
    //   Serial.println(number);
    // }
    // return number;
    return map(sq(value), 0, sq(40), 0, 255);
  }
}

void setLight(int values[]) {
  name(mapBrightness(values[0])); //story/memory
  religion(mapBrightness(values[1])); //identity 
  people(mapBrightness(values[2])); //collectivity
  kids(mapBrightness(values[3])); //activity
  house(mapBrightness(values[4])); //apperance 
  lamp(mapBrightness(values[5])); //comfort
  space(mapBrightness(values[6])); //spatial
  road(mapBrightness(values[7])); //infra
  canal(mapBrightness(values[8])); //location
  rubbish(mapBrightness(values[9])); //object
}

void loop() {
  int residents[10] = { 1, 14, 4, 15, 20, 3, 10, 4, 0, 6 };
  int visitors[10] = { 3, 11, 5, 5, 40, 1, 7, 2, 0, 1 };
  int professionals[10] = { 6, 14, 16, 19, 15, 3, 6, 5, 3, 5 };
  int governments[10] = { 5, 15, 10, 12, 3, 9, 9, 8, 4, 2 };
  int academics[10] = { 4, 20, 9, 5, 4, 4, 19, 4, 0, 2 };
  int makers[10] = { 11, 10, 3, 3, 3, 3, 25, 2, 1, 3 };
  int owners[10] = { 4, 21, 8, 11, 12, 8, 10, 5, 3, 3 };

  int result[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  for (int i = 0; i < 7; i++) {
    buttonState[i] = digitalRead(buttonPins[i]);
  }

  if (buttonState[0] == 1) {
    addArray(result, residents);
    Serial.println("residents");
  }

  if (buttonState[1] == 1) {
    addArray(result, visitors);
  }

  if (buttonState[2] == 1) {
    addArray(result, professionals);
  }

  if (buttonState[3] == 1) {
    addArray(result, governments);
  }

  if (buttonState[4] == 1) {
    addArray(result, academics);
  }

  if (buttonState[5] == 1) {
    addArray(result, makers);
  }

  if (buttonState[6] == 1) {
    addArray(result, owners);
  }

  setLight(result);
  FastLED.show();
}

void addArray(int* result, int array[]) {
  for (int i = 0; i <= 9; i++) {
    result[i] = array[i] + result[i];
  }
}
