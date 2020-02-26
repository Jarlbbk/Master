#include "Arduino.h"
class Timer_Func_And_Reed_Switch {
  private:
  
    const int pin; //the DIGITAL pin for the reed switch
    unsigned long time1;
    unsigned long time2;
    unsigned long total_time;
    int counter;
    int prox; //var proximity

  public:
    int proximity();
    Timer_Func_And_Reed_Switch(int PinNumber); 
    void setup(); 
    int loop();
};