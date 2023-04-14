// This program demonstrates the usage of Timers Overflow Interrupts.
// Configuring a Timer with a prescaler of 1024.
// Counting Frequency of Timer = 16,000,000 / 1024 = 15,625[Hz]
// Timer2 is 8-bit. Hence it can store values between 0-255.
// This timer is expected to be "re-filled" at 15,625/256 = ~61[Per Second]

// Enabling Timer2 "Overflow Interrupt". Once it reaches max value (to zero)
// it is expected to raise a "flag" and interrupt.

// This program also uses the ISR to handle the Timer OverFlow Interrupt.

// Global variable to keep track of the number of timer overflows
#define ZERO 0
#define VAL_TRIG 61

unsigned int timerCount = ZERO;

void setup()
{
  // Set pin 13 (PB5) as an output
  DDRB |= (1 << DDB5);
  
  // Disable interrupts
  cli();
  
  // Clear Timer2 control registers
  TCCR2A = ZERO;
  TCCR2B = ZERO;
  
  // Set Timer2 counter value to 0
  TCNT2 = ZERO;
  
  // Set Timer2 prescaler to 1024
  TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
  
  // Enable Timer2 overflow interrupt
  TIMSK2 |= (1 << TOIE2);
  
  // Enable interrupts
  sei();
}

// Interrupt Service Routine (ISR) for Timer2 overflow interrupt
ISR(TIMER2_OVF_vect)
{
  // Increment the timerCount variable
  ++timerCount;
  
  // If the timerCount variable has reached(i.e. 61 timer overflows), toggle the state of pin 13
  if (timerCount >= VAL_TRIG)
  {
    PORTB ^= (1 << PORTB5);
    // Reset the timerCount variable
    timerCount = ZERO;
  }
}

void loop()
{
  // Nothing to do here since all timing and pin toggling is handled by the Timer2 overflow interrupt
}
