#include <FastLED.h>

#define LED_PIN 3
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
}

void name(int brightness) {
}

void religion(int brightness) {
}

void people(int brightness) {
  // leds[7] = CRGB(brightness, brightness, brightness);
}

void kids(int brightness) {
}

void house(int brightness) {
  for (int i = 0; i <= 33; i++) {
    leds[i] = CRGB(brightness, brightness, brightness);
  }
}

void lamp(int brightness) {
}

void space(int brightness) {
}

void road(int brightness) {
  // for (int i = 15; i <= 22; i++) {
  //   leds[i] = CRGB(brightness, brightness, brightness);
  // }
}

void canal(int brightness) {
  // for (int i = 9; i <= 14; i++) {
  //   leds[i] = CRGB(brightness, brightness, brightness);
  // }
}

void rubbish(int brightness) {
  // leds[8] = CRGB(brightness, brightness, brightness);
}



long mapBrightness(int value) {
  if (value >= 40) {
    return 255;
  } else {
  return map(value, 0, 40, 0, 255);
  }
}

void setLight(int values[]) {
  name(mapBrightness(values[0]));
  religion(mapBrightness(values[1]));
  people(mapBrightness(values[2]));
  kids(mapBrightness(values[3]));
  house(mapBrightness(values[4]));
  lamp(mapBrightness(values[5]));
  space(mapBrightness(values[6]));
  road(mapBrightness(values[7]));
  canal(mapBrightness(values[8]));
  rubbish(mapBrightness(values[9]));
}

void loop() {
  int residents[10] = { 1, 14, 4, 15, 20, 3, 10, 4, 0, 6 };
  int visitors[10] = { 3, 11, 5, 5, 40, 1, 7, 2, 0, 1 };
  int professionals[10] = { 6, 14, 16, 19, 15, 3, 6, 5, 3, 5 };
  int governments[10] = { 5, 15, 10, 12, 3, 9, 9, 8, 4, 2 };
  int academics[10] = { 4, 20, 9, 5, 4, 4, 19, 4, 0, 2 };
  int makers[10] = { 11, 10, 3, 3, 3, 3, 25, 2, 1, 3 };
  int owners[10] = { 4, 21, 8, 11, 12, 8, 10, 5, 3, 3 };

  int result[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  addArray(result, visitors);
  setLight(result);
  FastLED.show();
}

void addArray(int* result, int array[]) {
  for (int i = 0; i <= 9; i++) {
      result[i] = array[i] + result[i];
  }
}


  // int test1[10] = { 0, 0, 40, 0, 40, 0, 0, 0, 0, 0 };
  // int test2[10] = { 0, 0, 30, 0, 0, 0, 0, 255, 40, 0 };
  // int test3[10] = { 50, 0, 50, 0, 0, 0, 0, 255, 40, 0 };
