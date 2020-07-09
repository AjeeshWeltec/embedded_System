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

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define Button_1Pin 12 //button 1 on pin 12
#define Button_2Pin 11 //button 2 on pin 11
#define DACpin A14
#define ADCpin 14
#define PotentiometerPin 16 //potentiometer signal on pin 16

uint8_t Button_1Status = 0; //status of button 1
uint8_t Button_1Press = 0; //for button 1  press
uint8_t Button_1Previouscount = 0; //previous press count of button 1
uint8_t Button_1Currentcount= 0; //current press count of button 1
uint8_t Button_2Status = 0; //status of button 2
uint8_t Button_2Press = 0; //for button 2  press
uint8_t Button_2Previouscount = 0; //previous press count of button 2
uint8_t Button_2Currentcount= 0; //current press count of button 2
uint32_t DebounceTime =200; //a delay for debounce


float voltage; //voltage value
float Var_R; //potentiometer value

void Button_1(); //function for calculating debounce delay of button_1
void Button_2(); //function for calculating debounce delay of button_2
void HomeScreen(); //function for initial display
void ModeSelection(); //selection screen 
void oscilloscope(); //function for oscilloscope- waveform forvoltage vs time


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
   pinMode(Button_1Pin,INPUT_PULLUP);
  pinMode(Button_2Pin,INPUT_PULLUP);
  pinMode(PotentiometerPin ,INPUT_PULLUP);
  attachInterrupt(Button_1Pin,Button_1,FALLING);
  attachInterrupt(Button_2Pin,Button_2,FALLING);
  }
void loop(){  
 static uint8_t DAC_Input = 0; //input for DAC pin
  union DAC_Input{
    int i;
    float f;
  } DAC;
  DAC.f = DAC_Input;
  if(Button_2Press == 0 and Button_1Press == 0){
    HomeScreen();
  } 
  if(Button_2Press > 0 and Button_1Press == 0){
    ModeSelection();
    display.clearDisplay();    
  }
  if((Button_2Press == 1) and (Button_1Press == 1)){ //loop function for mapping voltage across time
    static uint8_t x_Graph = 120;
    display.drawFastVLine(0,0, SCREEN_HEIGHT , WHITE);
    display.drawFastHLine(0,63, SCREEN_WIDTH , WHITE);
    Var_R = analogRead(PotentiometerPin );
    voltage = map(Var_R , 0, 255, 0, 1); //mapping volatge from 0 to 1 v
    float y_Graph = map(voltage, 0, 1, 63, 5);//mapping 0 to 1 volt to 63 , 5 y pixel
    display.setCursor(0,63);
    display.setTextSize(1);
    display.drawPixel(x_Graph , y_Graph, WHITE);
    x_Graph++;
    Serial.println(voltage);
        
    if(x_Graph > 120){
       x_Graph = 0;
       display.clearDisplay();
       }
    }
}

void HomeScreen() { //function for homescreen
 display.clearDisplay();
 display.setTextSize(2); // Draw 2X-scale text
 display.setTextColor(WHITE);
 display.setCursor(20, 20);//displaying at coordinates 20-x,20-y
 display.println("WELCOME");
 display.setTextSize(1);//font size 1X- scale
 display.println("ES -LOGIC ANALYSER");
 display.setCursor(0, 55);
 display.setTextSize(.1);//font size .1X- scale
 display.println("Press Button to Start");
 display.display();

}

void ModeSelection(){ //function for mode selection screen
 display.setTextSize(1.5);
 display.setTextColor(WHITE);
 display.setCursor(5,15);
 display.println("> OSZI MODE");
 display.setTextSize(1.5);
 display.setTextColor(WHITE);
 display.setCursor(5,25);
 display.println("> FUNC GEN MODE");
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(15,35);
 display.println("- SINE");
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
void Button_1(){ //debounce delay for button_1
  static uint32_t Button_1Previoustime = 0;
   Button_1Previouscount = Button_1Press;
   if((millis() - Button_1Previoustime)>= DebounceTime){
  
   Button_1Previoustime = millis();
   Button_1Press++;
   Button_1Status++;
   
   }
   Button_1Currentcount = Button_1Press;
}

void Button_2(){ // debounce delay for button_2
  static uint32_t Button_2Previoustime = 0;
   Button_2Previouscount = Button_2Press;
   if((millis()- Button_2Previoustime)>= DebounceTime){
  
   Button_2Previoustime = millis();
   Button_2Press++;
   Button_2Status++;
   
   }
   Button_2Currentcount = Button_2Press;
}