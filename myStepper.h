#include <Arduino.h>
#ifndef MYSTEPPER_H
#define MYSTEPPER_H

class myStepper
{
private:
    int pins[4];
    int pos;
    void incPos(int dir);
    void writeLow();
    float pause;
    float angle;
    float strideAngle;
    const int phase[4][4]={
        {1,0,0,1},
        {1,1,0,0},
        {0,1,1,0},
        {0,0,1,1}
    };
    const int stepsThroughPhase=4;

public:
    myStepper(float strideAngle, int p1, int p2, int p3, int p4);
    void setPause(float pause);
    float getAngle();
    float getPause();
    void setAngle(float angle);
    void setPhase(int which);
    void step(int steps, int dir);
    void stepAngle(float angle, int dir);
    ~myStepper();
};

#endif