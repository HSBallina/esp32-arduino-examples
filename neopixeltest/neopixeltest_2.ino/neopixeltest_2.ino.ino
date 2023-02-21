#include <Adafruit_NeoPixel.h>

#define LED_PIN 3
#define LED_COUNT 62
#define MAX_BRIGHT 127
Adafruit_NeoPixel strip (LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(100);
}

void loop() {
  for(int i=0;i<MAX_BRIGHT;i++){
    setAll(i);
      strip.show();
      delay(10);
  }
  delay(1000);
  
  for(int i=MAX_BRIGHT;i>=0;i--){
      setAll(i);
      strip.show();
      delay(10);
  }
  delay(500);
}

void setAll(int i){
      for(int j=0; j<strip.numPixels(); j++){
      strip.setPixelColor(j, strip.Color(i, 0, i));
    }
}
