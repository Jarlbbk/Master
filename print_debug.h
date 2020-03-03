//debugger. In the shape of a self made print function. This will be used instead of Serial.println()
//and it will only be compiled when #define DEBUGGER is defined otherwise it will do nothing
#pragma once
#include "Arduino.h"

#define DEBUGGER
#ifndef DEBUGGER
    # define print_debug()
#else 
    # define print_debug() Serial.print("you are on line: "); Serial.println( __LINE__); Serial.print("in file: "); Serial.println(__FILE__);
#endif