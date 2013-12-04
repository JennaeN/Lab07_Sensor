/*
 * Sensor.h
 *
 *  Created on: Dec 2, 2013
 *      Author: C15Jennae.Steinmiller
 */

#ifndef SENSOR_H_
#define SENSOR_H_

int movingAverage(int sampleStream[]);

void senseLeft();

void senseRight();

void senseCenter();

void IsLeftHighLow(int threshhold);

void IsRightHighLow(int threshhold);
#endif /* SENSOR_H_ */
