#include <myStepper.h>

myStepper::myStepper(float strideAngle, int p1, int p2, int p3, int p4)
{
    
    this->strideAngle=strideAngle;
    this->pins[0]=p1;
    this->pins[1]=p2;
    this->pins[2]=p3;
    this->pins[3]=p4;

    for(int pin : pins){
        pinMode(pin, OUTPUT);
    }

    this->pos=0;
    this->pause=2;
    this->angle=0;
}

void myStepper::stepAngle(float turnAngle,int dir){
    this->step(turnAngle/this->strideAngle, dir);
}

void myStepper::step(int steps, int dir){

    for(int i=0;i<steps;i++){
        for(int j=0;j<stepsThroughPhase;j++){
            digitalWrite(pins[j], phase[pos][j]);
        }
        incPos(dir);
        delay(pause);
    }
    writeLow();
}

void myStepper::writeLow(){
    for(int pin : this->pins){
        digitalWrite(pin, LOW);
    }
}

void myStepper::setPause(float pause){
    this->pause=pause;
}

void myStepper::incPos(int dir){

    this->pos+=dir;
    this->angle+=this->strideAngle;
    if(this->angle>360) this->angle=0;
    if(this->angle<0) this->angle=360;

    if(pos>stepsThroughPhase-1) pos=0;
    if(pos<0) pos=stepsThroughPhase-1;
}

float myStepper::getAngle(){
    return this->angle;
}
float myStepper::getPause(){
    return this->pause;
}

void myStepper::setAngle(float angle){
    this->angle=angle;
}

myStepper::~myStepper()
{
}