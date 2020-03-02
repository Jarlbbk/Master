#include "EKG.h"


EKG::EKG(int ana, int dig_low, int dig_high): ana_pin{ana}, dig_low_pin{dig_low}, dig_high_pin{dig_high}
{

}

void EKG::setup()
{
    pinMode(dig_high_pin, INPUT);
    pinMode(dig_low_pin, INPUT);
}


void EKG:: loop() 
{
    Serial.println(analogRead(ana_pin));
}


EKG::~EKG()
{
    
}
