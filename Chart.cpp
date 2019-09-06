#include <Chart.h>
#include <math.h>
#include <Arduino.h>
// Chart::Chart(int stepsPerRev, int p1sL, int p2sL, int p3sL, int p4sL, int p1sR, int p2sR, int p3sR, int p4sR, float R, float offset){
Chart::Chart(myStepper* stepL, myStepper* stepR, float R, float offset){
    this->offset=offset;
    this->R=R;

    // myStepper stepL(stepsPerRev, p1sL, p2sL, p3sL, p4sL);
    // myStepper stepR(stepsPerRev, p1sR, p2sR, p3sR, p4sR);

    this->stepL=stepL;
    this->stepR=stepR;

    this->currentPos.x=0;
    this->currentPos.y=sqrt(this->R*this->R-pow(this->offset,2));
}

void Chart::setPos(float x, float y){
    this->currentPos.x=x;
    this->currentPos.y=y;
}

point Chart::getPos(){
    return this->currentPos;
}

void Chart::reset(){
    this->currentPos.x=0;
    this->currentPos.y=0;
}

void Chart::testL(){
    this->stepL->stepAngle(90,1);
}

void Chart::testR(){
    this->stepR->stepAngle(90,1);
}

void Chart::goTo(float x, float y){
	double angleL, angleR, xL, xR, rL, rR;

	// distance from stepper centre to point
	xL=x+this->offset;
	xR=x-this->offset;

	rL=sqrt(pow(xL,2)+pow(y,2));
	rR=sqrt(pow(xR,2)+pow(y,2));

	// angle between line drawn between stepper and and point and lower arm
	// double thetaL=acos(rL/(2*R));
	// double thetaR=acos(rR/(2*R));

    // Serial.println(thetaL);
	
	// combine angle below line drawn to point and horz and angle above drawn to arm

    angleL=acos(rL/(2*R))+atan(y/xL);
    angleR=acos(rR/(2*R))+atan(y/xR);


	// get current stepper angle
	double currentL=this->stepL->getAngle()*PI/180;
	double currentR=this->stepR->getAngle()*PI/180;

	// get difference in desired angle vs. current angle to step through. Determine whether
	// stepping forwards or backwards. Question mark is called a ternary operator.

    // Serial.println("---");
    // Serial.println(abs(angleL-currentL));
    // Serial.print("Calc angle: ");
    // Serial.println(angleL);
    // Serial.println("");
    // Serial.print("Curr angle: ");
    // Serial.println(currentL);
    // Serial.println("");
    // Serial.print("Diff angle: ");
    // Serial.println(angleL-currentL);
    // Serial.print("direction: ");
    // Serial.println((angleL-currentL>0) ? 1 : -1);

	stepL->stepAngle(abs(angleL-currentL)*180/PI,(angleL-currentL>0) ? 1 : -1); 
	stepR->stepAngle(abs(angleR-currentR)*180/PI,(angleR-currentR>0) ? 1 : -1);

    // Serial.print("After angle: ");
    // Serial.println(stepL->getAngle()*PI/180);
    // Serial.println("---------------");

    this->setPos(x,y);
}