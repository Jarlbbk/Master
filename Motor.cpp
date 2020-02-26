#include "Arduino.h"
#include "Motor.h"
#include "FSR.h"


Motor::Motor(int pin1, int pin2, FSR* fsr_ref) : MOTOR_IN1{pin1}, MOTOR_IN2{pin2}, fsr(fsr_ref), motor_speed{0} 
{	 
}

Motor::~Motor() 
{
}

void Motor::setup()
{
	pinMode(MOTOR_IN1, OUTPUT);
	pinMode(MOTOR_IN2, OUTPUT);
}

void Motor::loop()
{
	int FSRreading = fsr->loop(); //to use member function for a pointer member variable, use ->
	motor_speed = map(FSRreading, 0, 1023, 0, 255);
	analogWrite(MOTOR_IN1, motor_speed); //for now this only allows the motor to move in one direction, 
	//I need to write to MOTOR_IN2 to get it the other way
	
}
