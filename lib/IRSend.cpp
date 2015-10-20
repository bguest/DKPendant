#include "IRSend.h"

#define PWMFREQUENCY  38000 // Frequency in Hz

#define SAMSUNG_BITS          32
#define SAMSUNG_HDR_MARK    5000
#define SAMSUNG_HDR_SPACE   5000
#define SAMSUNG_BIT_MARK     560
#define SAMSUNG_ONE_SPACE   1600
#define SAMSUNG_ZERO_SPACE   560
#define SAMSUNG_RPT_SPACE   2250

#define MARK  (TCCR1 |= _BV(COM1A1)); // Enable pin 6 (PB1) PWM output
#define SPACE (TCCR1 &= ~(_BV(COM1A1))); // Disable pin 6 (PB1) PWM output

IRSend::IRSend(){
}

void  IRSend::sendSAMSUNG (unsigned long data,  int nbits)
{
	// Header
  MARK
	delayMicroseconds(SAMSUNG_HDR_MARK);
  SPACE
	delayMicroseconds(SAMSUNG_HDR_SPACE);

	// Data
	for (unsigned long  mask = 1UL << (nbits - 1);  mask;  mask >>= 1) {
		if (data & mask) {
      MARK
			delayMicroseconds(SAMSUNG_BIT_MARK);
      SPACE
			delayMicroseconds(SAMSUNG_ONE_SPACE);
		} else {
      MARK
			delayMicroseconds(SAMSUNG_BIT_MARK);
      SPACE
			delayMicroseconds(SAMSUNG_ZERO_SPACE);
		}
	}

	// Footer
  MARK
	delayMicroseconds(SAMSUNG_BIT_MARK);
  SPACE
}

void IRSend::init(){

  cli(); // Disables interrupts by setting the global interrupt mask

  /* Set up I/O's */
  DDRB |= _BV(IRLED); // Set as output
  PORTB &= ~(_BV(IRLED)); // When not sending PWM, we want it low

  /* Disable Analog to Digitalconverter to save power */
  //ADCSRA &= ~(_BV(ADEN));

  /* Enable PWM with a frequency of 38kHz on pin 6 (OC1A) */
  TCCR1 = _BV(PWM1A) | _BV(CS12); // Enable PWM and set prescaler to 8
  OCR1C = (((F_CPU/8/PWMFREQUENCY))-1); // Set PWM Frequency to 38kHz, OCR1C is TOP, see the datasheet page 90
  OCR1A = OCR1C/3; // 33% duty cycle

  sei(); // Enables interrupts by setting the global interrupt mask
}

