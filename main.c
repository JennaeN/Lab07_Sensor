#include <msp430g2553.h>
#include "Sensor.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	senseLeft();

	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0; // Select SMCLK (this is the slowest clock)
	P1DIR |= (BIT0|BIT6);                            // Set P1.0 and P1.6 to output


	for (;;) {

		senseLeft();

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		__bis_SR_register(CPUOFF + GIE);
		// LPM0, ADC10_ISR will force exit

		IsLeftHighLow(0x2FF);

		senseRight();

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		__bis_SR_register(CPUOFF + GIE);
		// LPM0, ADC10_ISR will force exit

		IsRightHighLow(0x2FF);
	}

	return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}

