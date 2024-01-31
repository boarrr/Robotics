
void turn90degreesLeft();
void turn90degreesRight();
void goForward1second();
void swingRight90degrees();
void swingLeft90degrees();
void reverse1second();
void resetMotor();

task main()
{
	turn90degreesLeft();
	sleep(1000);

	turn90degreesRight();
	sleep(1000);

	goForward1second();
	sleep(1000);

	swingRight90degrees();
	sleep(1000);

	swingLeft90degrees();
	sleep(1000);

	reverse1second();
}

void turn90degreesLeft()
{
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, 50);

	sleep(420);

	resetMotor();
}

void turn90degreesRight()
{
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, -50);

	sleep(420);

	resetMotor();
}

void goForward1second()
{
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 50);

	sleep(1000);

	resetMotor();
}

void swingRight90degrees()
{
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 10);
	sleep(1000);

	resetMotor();
}

void swingLeft90degrees()
{
	setMotorSpeed(motorB, 10);
	setMotorSpeed(motorC, 50);
	sleep(1000);

	resetMotor();
}

void reverse1second()
{
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, -50);
	sleep(1000);

	resetMotor();
}

// Reset motors to 0 speed for repeated movements
void resetMotor()
{
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}
