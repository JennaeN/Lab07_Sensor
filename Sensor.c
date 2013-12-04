#include <msp430g2553.h>

/*
 * Sensor.c
 *
 *  Created on: Dec 2, 2013
 *      Author: C15Jennae.Steinmiller
 */
//
//int movingAverage(int sampleStream[]) {
//
//	char run = 1;
//	char i;
//
//	unsigned int sampleValue1 = sampleStream[0];
//
//	int average = 0;
//
//	for (i = 1; i <= N_AVG_SAMPLES; i++) {
//		average += sampleValue1;        // + sampleValue2;
//		sampleValue1 = sampleStream[i + run - 1];        //sampleValue2;
//
//	}
//	average = average / N_AVG_SAMPLES;
//	sampleValue1 = sampleStream[run];
//
//	int averages[LENGTH - 1];
//	averages[run - 1] = average;
//	run++;
//
//	return average;
//}

void senseLeft() {
	ADC10CTL0 &= ~ENC;             // Sampling and conversion stop
	ADC10CTL1 = INCH_4;                       // input channel A4
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select

}

void senseRight() {
	ADC10CTL0 &= ~ENC;             // Sampling and conversion stop
	ADC10CTL1 = INCH_5;                       // input channel A5
	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
}

void senseCenter(){
	ADC10CTL0 &= ~ENC;             // Sampling and conversion stop
	ADC10CTL1 = INCH_3;						//input channel A3
	ADC10AE0 |= BIT3;							// PA ADC option select
}

void IsRightHighLow(int threshhold) {
	if (ADC10MEM < threshhold) {
		P1OUT &= ~BIT6;                      // Clear P1.6 LED off
		//return 0;
	} else {
		P1OUT |= BIT6;                       // Set P1.6 LED on
		//return 1;
	}
}

void IsLeftHighLow(int threshhold) {
	if (ADC10MEM < threshhold) {
		P1OUT &= ~BIT0;                      // Clear P1.6 LED off
		//return 0;
	} else {
		P1OUT |= BIT0;                       // Set P1.6 LED on
		//return 1;
	}
}
