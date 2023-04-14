# Timed-LED-Blinker-using-Interrupts
The project demonstrates the usage of Timers Overflow Interrupts. It configures a Timer with a prescaler of 1024 and counts the frequency of the timer as 15,625 [Hz]. The program uses Timer2, which is 8-bit and can store values between 0-255. The timer is expected to be "re-filled" at 61 times per second.

## Getting Started
These instructions will guide you on how to run the program on your system.

## Prerequisites
The following are the requirements to run the program:

* A microcontroller board (e.g. Arduino)
* A computer with Arduino IDE installed
* A USB cable
## Installing
1. Connect the microcontroller board to your computer via USB cable
2. Open the Arduino IDE
3. In the IDE, select the appropriate board and port under the Tools menu
4. Copy and paste the program code into a new sketch
5. Upload the sketch to the board by clicking on the "Upload" button
## Usage
The program is designed to demonstrate the usage of Timers Overflow Interrupts. When the program is uploaded to the board, it will automatically start running. The program uses Timer2 to toggle the state of pin 13 (PB5) at a frequency of 61 times per second.

## Contributing
If you would like to contribute to the project, please fork the repository and create a pull request. Your contribution is appreciated.

## Code Description
The program starts by setting pin 13 (PB5) as an output and disabling interrupts. It then clears the Timer2 control registers and sets the Timer2 counter value to 0. The Timer2 prescaler is set to 1024, and the Timer2 overflow interrupt is enabled. Interrupts are then enabled.

The program uses an Interrupt Service Routine (ISR) for Timer2 overflow interrupt. The ISR increments a global variable timerCount. If the timerCount variable has reached 61 timer overflows, the state of pin 13 is toggled, and the timerCount variable is reset to 0.

The loop() function is empty since all timing and pin toggling is handled by the Timer2 overflow interrupt.

## Authors
Eden Sheiko
License
This project is licensed under the MIT License - see the LICENSE.md file for details.
