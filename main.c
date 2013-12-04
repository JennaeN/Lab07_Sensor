#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_4;                       // input channel A4
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0; // Select SMCLK (this is the slowest clock)
	P1DIR |= (BIT0|BIT6);                            // Set P1.0 and P1.6 to output


	for (;;) {

		ADC10CTL1 = INCH_4;                       // input channel A4
		ADC10AE0 |= BIT4;                         // PA.1 ADC option select

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		__bis_SR_register(CPUOFF + GIE);
		// LPM0, ADC10_ISR will force exit

		if (ADC10MEM < 0x2FF){		//was 0c0
			P1OUT &= ~BIT0;                       // Clear P1.0 LED off
		}
		else{
			P1OUT |= BIT0;                        // Set P1.0 LED on
		}

		ADC10CTL0 &= ~ENC;             // Sampling and conversion stop to allow us to change bits
		ADC10AE0 &= ~BIT4;
		ADC10CTL1 = INCH_5;                       // input channel A5
		ADC10AE0 |= BIT5;                         // PA.1 ADC option select
		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
		__bis_SR_register(CPUOFF + GIE);
		// LPM0, ADC10_ISR will force exit

		if (ADC10MEM < 0x2FF){
			P1OUT &= ~BIT6;                      // Clear P1.6 LED off
		}
		else	{
			P1OUT |= BIT6;                       // Set P1.6 LED on
		}

		ADC10CTL0 &= ~ENC;             // Sampling and conversion stop
		ADC10AE0 &= ~BIT5;
	}

	return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}
