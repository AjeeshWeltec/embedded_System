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

//#define LOGO_HEIGHT   16
//#define LOGO_WIDTH    16
#define DACpin A14
#define ADCpin 14
#define Buttonpin 12

uint8_t ButtonMode =0;
int8_t ButtonPress =0;
uint8_t previousButtoncount =0;
uint8_t currentButtoncount =0;
uint32_t debouce_delay =0;

void Button(); 
void HomeScreen();
void ModeSelection();

void setup() 
  {
   analogWriteResolution(8);
   analogReadResolution(8);
   Serial.begin(9600);
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    { 
     Serial.print("DISPLAY-ERORR!!!");
     for(;;); // Don't proceed, loop forever
    }
   pinMode(Buttonpin, INPUT_PULLUP);
   //attachInterrupt(Buttonpin, Button, FALLING);
  }
void loop(){  
 if(ButtonPress==0){
   HomeScreen();
  }
  if(!digitalRead(Buttonpin)){
  ModeSelection();
  ButtonPress = 1;  
 }
}

void HomeScreen() {
 display.clearDisplay();
 display.setTextSize(2); // Draw 2X-scale text
 display.setTextColor(WHITE);
 display.setCursor(20, 20);//displaying at coordinates 20-x,20-y
 display.println("WELCOME");
 display.setTextSize(1);//font size 1X- scale
 display.println("ES -LOGICAL ANALYSER");
 display.setCursor(65, 55);
 display.setTextSize(.5);//font size 1X- scale
 display.println("-AJEESH");
 display.display();
 ButtonPress = 1;
}

void ModeSelection(){
 display.clearDisplay();
 display.setTextSize(1.5);
 display.setTextColor(WHITE);
 display.setCursor(5,5);
 display.println("> OSCILLOSCOPE");
 display.setTextSize(1.5);
 display.setTextColor(WHITE);
 display.setCursor(5,15);
 display.println("> FUNCTION GENERATOR");
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(15,25);
 display.println("- SINE");
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(15,35);
 display.println("- TRIANGLE");
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(15,45);
 display.println("- SQUARE");
 display.setTextSize(1.5);
 display.setTextColor(WHITE);
 display.setCursor(5,55);
 display.println("> LOGIC ANALYSER"); 
 display.display();
}
