Lab07_Sensor- A/D Conversion - "Robot Sensing"
=====================================

Grading
-----------

Item                                                                    	  Grade 	                                             Points 	Out of 	Date 	Due
Prelab 	On-Time: 0 --------------------- Check Minus ---- Check ---- Check Plus 	                         	10 		BOC L37
Required Functionality 	On-Time----- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		               40 		COB L38
B Functionality 	On-Time------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                 		10 		COB L38
A Functionality 	On-Time------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 	                	10 		COB L38
Use of Git / Github 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ----
                                                              Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                		10 		COB L40
Code Style 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- 
                                                             Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                 		10 		COB L40
README 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- 
                                                            Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 	                  	10 		COB L40
Total                                                                                                                                  		          	100 	



Overview
--------------

This lab is designed to assist you in learning the concepts associated with the analog-to-digital
converter (ADC) for your MSP430. A set of three infrared (IR) emitter and detector pairs on your
robot is used to bring in analog voltage values for the ADC. You will program your MSP430 to 
interpret these incoming voltages to determine whether your mobile robot is approaching a wall in front or on one of its sides. 


Sensor Boards
------------------

Each robot has three IR emitter/detector pairs. 
By using the headers available to you on the top of the robot PCB, you can read a value between
0 V and 5 V that is proportional to the distance to an object in front of the IR sensor. The left/right directions are relative to a person standing behind the robot.

ATD Conversion
-----------------------

You will use the ADC to sample three channels with a single sample per channel. The values
you display for the instructor must be the average of the last four samples. This moving 
average always stores the last four samples and takes the average. For each additional sample,
there is a new average computed. Note: You do not just sample four values, take the average,
sample another four value, take that average, etcetera. A moving average computes a new average
for each new ATD sample. The oldest value is dropped when a new one comes in. This serves as 
a low pass filter on the values to prevent extreme jumps due to noise. If needed, you may increase
the sample window as needed to reduce the noise.

Your results must be shown using the Real-Time Debugger.

Sensor Characterization
----------------------------

Since each robot's sensors are a little bit different, you need to fully characterize the
sensor for your robot. Create a table and graphical plot that shows the ATD values for a 
variety of distances from a maze wall. This table/graph must be generated for each IR sensor.
Use these values to determine how the IR sensors work so you can properly use them to solve
the maze. Are the results linear? Do they change much for walls facing different directions?
Does the lighting/shadows affect the values?


Required Functionality
------------------------------

Use the ADC subsystem to light LEDs based on the presence of a wall. The presence of a wall next to the left sensor should light LED1 on your Launchpad board. The presence of a wall next to the right sensor should light LED2 on your Launchpad board. Demonstrate that the LEDs do not light until they come into close proximity with a wall.

B Functionality
-------------------

Create a standalone library for your ATD code and release it on Github. This should be separate from your lab code. It should have a thoughtful interface and README, capable of being reused in the robot maze laboratory.

A Functionality
-------------------

Since each robotbs sensors are a little bit different, you need to fully characterize the sensor for your robot. Create a table and graphical plot that shows the ATD values for a variety of distances from a maze wall. This table/graph must be generated for each IR sensor. Use these values to determine how the IR sensors work so you can properly use them to solve the maze.

Prelab
--------

Paste the grading section in your lab notebook as the first page of this lab.
Include whatever information from this lab you think will be useful in creating your program.
Test your sensors with a DMM. Ensure they are functional. What would good reference values be?
Consider how you'll setup the ADC10 subsystem. What are the registers you'll need to use? Which bits in those registers are important? What's the initialization sequence you'll need?
Consider the hardware interface. Which ADC10 channels will you use? Which pins correspond to those channels?
Consider the interface you'll create to your sensors. Will you block or use interrupts? Will you convert one sensor at a time or multiple?
