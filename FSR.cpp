#include "FSR.h"
#include "Arduino.h"


FSR:: FSR(int pinNumber) : pin{pinNumber}   {}

int FSR::loop() 
{
	int ans = analogRead(pin);
	return ans;
}

void FSR::setup() 
{
	pinMode(pin,INPUT);
}