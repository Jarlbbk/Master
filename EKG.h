//this class is for the use of AD8232 Sparkfun Single lead heart rate monitor
//the setup and void function are simply what is needed to setup and read the input from the AD8232
#pragma once

#include "Arduino.h"

class EKG 
{
    private:
        int ana_pin;
        int dig_low_pin;
        int dig_high_pin;
    public:
        EKG(int ana, int dig_low, int dig_high);
        void setup();
        void loop();
        ~EKG();
};