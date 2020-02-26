#include "Arduino.h"
class FSR 
{
	private:
		int pin;
	public:
		FSR(int pinNumber);
		int loop(); 
		void setup();
};