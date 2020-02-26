#pragma once

#include "Arduino.h"
#include "FSR.h"



class Motor 
{
	private:
		const int MOTOR_IN1; //pin to motor driver
		const int MOTOR_IN2; //pin to motor driver
		FSR *fsr; //can not use a reference as member variable, use pointer 
		int motor_speed;
	public:
		
		Motor(const int MotorPin1, const int MotorPin2, FSR* fsr_ref); //the MotorPins must be PWM pins
		// for fsr_ref must first initialize an FSR object, then I must creat an FSR* to that FSR objetc,
		this FSR* must go in Motor constructor 
		~Motor();
		void setup();
		void loop();


};

