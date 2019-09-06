#include <Arduino.h>
#include <myStepper.h>
#include <Chart.h>


const int p1sL = 12;
const int p2sL = 11; // (unipolar) stepper pins
const int p3sL = 10;
const int p4sL = 9;

const int p1sR = 8;
const int p2sR = 7; // (unipolar) stepper pins
const int p3sR = 6;
const int p4sR = 5;

float strideAngle = 5.625/64;

#define OFFSET 40 // x offset of rotation centre from centre
#define R 70 // length arms (assumed all are the same)

// myStepper* stepL = new myStepper(strideAngle, p1sL, p2sL, p3sL, p4sL);
// myStepper* stepR = new myStepper(strideAngle, p1sR, p2sR, p3sR, p4sR);
// Chart chart(stepL, stepR, R, OFFSET);

void setup() {
	Serial.begin(9600);
}

void loop() {
	
	
}