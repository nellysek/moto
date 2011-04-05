unsigned char leftMotor;
unsigned char rightMotor;
unsigned char frontMotor;
unsigned char rearMotor;
unsigned char leftPulse;
unsigned char rightPulse;
unsigned char frontPulse;
unsigned char rearPulse;

unsigned char startMotors()
{
	leftPulse = 62;
    rightPulse = 62;
	frontPulse = 62;
	rearPulse = 62;
	analogWrite(lefMotor, leftPulse);
	analogWrite(rightMotor, rightPulse);
	analogWrite(frontMotor, frontPulse);
	analogWrite(rearMotor, rearPulse);
	return 1;
}

unsigned char stopMotors()
{
	leftPulse = 0;
    rightPulse = 0;
	frontPulse = 0;
	rearPulse = 0;
	analogWrite(lefMotor, leftPulse);
	analogWrite(rightMotor, rightPulse);
	analogWrite(frontMotor, frontPulse);
	analogWrite(rearMotor, rearPulse);
	return 0;
}

unsigned char increaseMotorPulse(unsigned char motor, unsigned char pulse)
{
	if(pulse < 252)
	{
		pulse = pulse + 3;
		analogWrite(motor, pulse);
		return pulse;
	}
	return 255;
}

unsigned char increaseMotorPulsePanic(unsigned char motor, unsigned char pulse)
{
	if(pulse < 249)
	{
		pulse = pulse + 6;
		analogWrite(motor, pulse);
		return pulse;
	}
	return 255;
}

unsigned char decreaseMotorPulse(unsigned char motor, unsigned char pulse)
{
	if(pulse > 3)
	{
		pulse = pulse - 3;
		analogWrite(motor, pulse);
		return pulse;
	}	
	return 3;
}

unsigned char decreaseMotorPulsePanic(unsigned char motor, unsigned char pulse)
{
	if(pulse > 6)
	{
		pulse = pulse - 6;
		analogWrite(motor, pulse);
		return pulse;
	}	
	return 3;
}
		
