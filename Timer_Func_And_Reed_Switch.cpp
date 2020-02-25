#include "Timer_Func_And_Reed_Switch.h"
#include "Arduino.h"


Timer_Func_And_Reed_Switch::Timer_Func_And_Reed_Switch(int PinNumber) : counter{0}, pin{PinNumber} {}

void Timer_Func_And_Reed_Switch::setup() {
      pinMode(pin, INPUT_PULLUP);
    
    }

int Timer_Func_And_Reed_Switch::loop() {
      proximity = digitalRead(pin); //Read the state of the reed switch
      if (proximity == LOW && counter == 0) {
            time1 = millis(); //measure the time at first instance of magnet passing
            counter = 1;	
      }

      if (proximity == HIGH && counter == 1){
            counter = 2;
        }
      
      if (proximity == LOW && counter == 2){
            time2 = millis(); //time when passing second magnet
            total_time = time2-time1;
            counter = 3;
    
        }

        if (proximity == HIGH && counter == 3) {
            counter = 0;
	    return total_time; //Must return the time it has taken to store it for the statistics
        }

    
    
  }