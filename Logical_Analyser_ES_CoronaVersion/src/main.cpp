/*
|AJEESH CHANDRAN|
|STUDENT ID :-2192556|
|MG7013|EMBEDDED SYSTEM ASSIGNMENT:- LOGICAL ANALYSER CORONA VERSION|
*/
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
 void testwelcometext(void);
  void setup() {
  Serial.begin(115200);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.print("SSD1306 allocation failed");
    for(;;); // Don't proceed, loop forever
  }
testwelcometext();    // Draw welcome text
  }
  void loop(){  
  }
  void testwelcometext(void) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE,BLACK);
  display.setCursor(20, 20);//displaying at coordinates 20-x,20-y
  display.println("WELCOME");
  display.setTextSize(1);//font size 1X- scale
  display.println("ES -Logical Analyser");
  display.display();      // Show initial text
  delay(100);

}
