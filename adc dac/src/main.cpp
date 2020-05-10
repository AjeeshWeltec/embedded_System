#include <Arduino.h>

#define DAC_Pin A14
#define ADC_Pin A1

void setup() {
  analogWriteResolution(8);
  analogReadResolution(8);
  Serial.begin(115200);
}
void loop(){
  static uint32_t previousMillis = 0;
  static int32_t counter = 0;

  uint32_t DAC_Input = 0;

  DAC_Input = sin((double)counter/100)*127 +127;

  analogWrite(DAC_Pin,DAC_Input); // 8bit DAC 0...2^8-1 0...255 0...3.3v
  uint32_t ADC_RAW_Value = analogRead(ADC_Pin); //8 bit DAC 0..2^8-1 0...255 0..3.3v

  float ADC_Value_Volt = (double)map(ADC_RAW_Value,0,255,0,3300)/1000;

  Serial.print(ADC_RAW_Value);
  Serial.print(",");
  Serial.print(ADC_Value_Volt);
  Serial.flush();

  while((micros()- previousMillis) <=10000){
 //do nothing
  }
  previousMillis = micros();
  counter++;
}