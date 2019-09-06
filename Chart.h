#ifndef CHART_H
#define CHART_H

#include <Arduino.h>
#include <myStepper.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

class Chart
{
public:
    Chart(myStepper* stepL, myStepper* stepR, float R, float offset);
    void setPos(float x, float y);
    void goTo(float x, float y);
    void reset();
    point getPos();
    void testR();
    void testL();

private:
    myStepper* stepL;
    myStepper* stepR;
    point currentPos;
    float offset;
    float R;
};

#endif