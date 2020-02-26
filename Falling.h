#pragma once

#include "Arduino.h"
#include "FSR.h"
#include "Timer_Func_And_Reed_Switch.h"

class Falling 
{
    private:
        FSR* fsr;
        Timer_Func_And_Reed_Switch* TFRS;
        int counter;
        int answer;
        int passing_of_magnet;
        int FSR_reading;
        int walking;
    public:
        Falling(FSR* fs, Timer_Func_And_Reed_Switch* T);
        int is_walking();
        int loop();
        ~Falling();

};