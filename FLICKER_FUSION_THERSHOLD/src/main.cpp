#include <Arduino.h>
/* assignment0 Flicker Fusion Thershold
   by Ajeesh chandran
   student ID 219256 */


#define led 13      // LED pin (inbuilt)
#define button_pin 14   // pin to which button is connected
#define potentiometer 15  // pin to which the potentiometer is connected

unsigned long debounceTime = 200;    // to avoid the flickering

float SetTime = 0;//store time for frequency
uint8_t SetFrequency;//blinking frequency
uint32_t pot_value = 0;// value from potentiometer


void IS_Routine()
{   
   static unsigned long previous_buttonpresstime = 0;// time for previous button press 
   unsigned long current_buttonpresstime = millis();// time for current button press 
   
   //  to avoid debounce 
   if((current_buttonpresstime - previous_buttonpresstime>= debounceTime )) 
   { 
        Serial.print("Frequency :  ");
        Serial.print(SetFrequency);// current frequency wil be displayed
        Serial.print("Hz");
        Serial.print("\n");
        previous_buttonpresstime = current_buttonpresstime;
   }  
}

void setup() 
{
 //declaring button_pin as input and led as output
  Serial.print(115200);
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(button_pin, IS_Routine, FALLING);// interrupt function call when button is pressed
}

void loop()
{
    static uint32_t blink_time = 0;// Time in millis starts when led is starts to blink
    uint32_t timer = millis();//loop entering time
    uint32_t display_time = 0;// making sure the frequency value doesnot print often
    uint32_t display_previoustime = 0;// storing the last tie after the first display

    pot_value=analogRead(potentiometer);  
    // frequency range(1,10) is ploted
    SetFrequency = map(pot_value, 1, 1023, 1, 10);

    //coding for conversion of frequency to Time period
    SetTime = (1.0/SetFrequency) * 1000.0;
    for(blink_time = millis() ;timer - blink_time <=(SetTime/2);)
    {
      digitalWrite(led, HIGH);//Led  turns  ON
      timer = millis();
    }
    for(blink_time= millis() ;timer - blink_time <=(SetTime/2);)
    {
       digitalWrite(led, LOW);//Led turns OFF
       timer= millis();           
    }  
    
    // coding for plotting frequency only  when the button is pressed
    display_time = millis();
    if(!digitalRead(button_pin)&& (display_time - display_previoustime)>= (100*debounceTime))
    {  
       Serial.print(SetFrequency);
       display_previoustime = display_time;
    }
         
}


