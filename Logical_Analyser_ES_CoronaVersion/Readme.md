# **MG7013 EMBEDDED SYSTEM**

## Assignment2

## -

##

## **Logic Analyser + Minimal Oscilloscope+ Signal generator**

Submitted By :- **Ajeesh Chandran** | Student ID :- **2192556**

Date:-10/07/2020

**ABSTRACT**

This project is intended to implement a microcontroller based system that provides a one channel oscilloscope, logic analyzer and a signal generator using an OLED.

**AIM**

1. Design a one channel oscilloscope(0-3.3v) using the microcontroller ADC peripheral.
2. Design a one channel function generator using the microcontroller DAC with the option to select between at least a square, triangle and sin signal
3. Design a one channel logic analyzer that allows for decoding 9600 baud serial frame
4. Display above mentioned modes with relevant signals streamed out in &quot;real-time&quot; via UART(-\&gt;USB) to a connected PC and visualised using a serial plotter and in parallel displayed on the OLED.
5. Control all the different modes via connected push buttons and in parallel via commands send from PC to microcontroller.
6. Structure and implement the system as a finite state machine.

**PROJECT DESIGN**

The system is designed using

- Teesny 3.2 development board :- It is a microcontroller with 72MHz arm cortex M4 architectural and micro USB port. The program is executed to the Teensy board via USB cable connected to the PC.
- PC with Visual Code Studio.
- An OLED Display:- It is a 128x64 segment monochrome single chip display driver that communicate via I2C protocol. The used display comes under class SSD1306 with address 0x3c. Connection port includes SDA,SCL,VCC &amp;GND. Power required is provided by 3.3v from Teensy.
- Potentiometer:- A variable resistance of 10K used to obtain the waveform on oscilloscope showing change in voltage across time.
- 2 Push Button: For switching the system state to different modes.

Hardware Connection

-Teensy pin A14 (DAC pin) and pin 14 shorted to read ADC out

-OLED pins from Teesny are VCC-3.3v, GND-gnd,SCL-19 and SDA-18

-Potentiometer connected to pin 16

-Button\_1 and Button\_2 are to pins 12 and 11 respectively

Coding

All the coding required for the prototype is programmed in visual code studio. The libraries used for OLED are Adafruit\_GFX and Adafruit\_SSD1306. Wire.h library is used for the I2C interfacing between the OLED and Teesny board.

System as a finite State Machine

The project is structured as a finite state machine. The event, state and action of the system are

- Events:- Button\_1 Pressed , Button\_2 Pressed.
- State:- Oszi mode, Func Gen Mode, Sine, Square &amp; Logic Analyser.
- Action:-waveform of voltage across time, Sine wave, Square wave and Bit pattern representation.

Schematics

- Fig 2.0 represents the Hardware Connection.
- Fig 2.1 represents the circuit diagram.
- Fig 2.2 represents the finite state diagram of the system.

All the schematics are attached in the Schematic Folder.

Working

- As the program is flashed the system displays Home screen.
- On Button\_2 press the screen changes to Mode selection screen.
- From mode selection screen each state can be selected on the basic of number of times the Button\_2 is pressed.
- The system switches to &#39;OSZI MODE&#39;, &#39;FUNC GEN MODE&#39; or &#39;LOGIC ANALYZER&#39; on Button\_1 press depending upon the Button\_2 press count.
- Back to Mode selection screen from each state is carried out on Button\_2 press.
- Generally mode selection assigned to Button\_2 and Action is carried out by Button\_1.

**DISCUSSON &amp; LIMITATIONS**

Limitations of my design are

- I have used the button press count for the selection of each mode, any chance in the number of button\_2 press doesn&#39;t give the desired mode state. A selection scroller should have done a replaced this issue, but the OLED display had some artifact that doesn&#39;t gives the display on top area of the screen.
- Flickering of mode selection screen

The task provided for the assignment have been achieved with the above limitations. For the function generator the waves generated was limited to sine and square waveform. Coding using enum datatype and &#39;switch&#39; function can make the program more compact since coding of &#39;nested if&#39; is a long coding process.

**RESULT**

The output required for the task was obtained successfully with

- Implementation of a start screen ,menu screen and a mode screen that provides a one channel oscilloscope, function generator and a logic analyser
- System is designed and implemented as finite state machine
- The working video demonstration of the project is: [https://www.youtube.com/watch?v=kFvIYnJp1SY](https://www.youtube.com/watch?v=kFvIYnJp1SY)

**REFERENCES**

- Burgess, P. (n.d.). Adafruit GFX Graphics Library. Retrieved July 09, 2020, from[https://learn.adafruit.com/adafruit-gfx-graphics-library/coordinate-system-and-units](https://learn.adafruit.com/adafruit-gfx-graphics-library/coordinate-system-and-units)
- Tripoli, S., Santos, R., John, Marin, C., Bello, S., Gorki, . . . E., E. (2019, September 08). Guide for I2C OLED Display with Arduino. Retrieved July 09, 2020, from [https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/](https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/)
- Https://moodle.weltec.ac.nz/pluginfile.php/639617/mod\_resource/content/0/Ass2\_Logic\_Analyser\_ES\_CoronaVersion.pdf. (n.d.). Retrieved July 5,2020,from[https://moodle.weltec.ac.nz/pluginfile.php/639617/mod\_resource/content/0/Ass2\_Logic\_Analyser\_ES\_CoronaVersion.pdf](https://moodle.weltec.ac.nz/pluginfile.php/639617/mod_resource/content/0/Ass2_Logic_Analyser_ES_CoronaVersion.pdf)