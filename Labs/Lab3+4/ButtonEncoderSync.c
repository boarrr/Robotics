#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

void drive(long nMotorRatio, long dist, long power);
void reset();

#define circumfrance 17.6

task main()
{
	int distance = 0;
	int power = 0;


	while(getButtonPress(buttonEnter) == 0)
	{
		displayBigTextLine(4, "%d cm distance", distance);

		if (getButtonPress(buttonUp))
		{
			distance = 10;
		}
		else if (getButtonPress(buttonDown))
		{
			distance = 40;
		}
		else if (getButtonPress(buttonLeft))
		{
			distance = 60;
		}
		else if (getButtonPress(buttonRight))
		{
			distance = 80;
		}
	}

	while(power < 10)
	{
		power = random(100);
	}

	drive(0, distance, power);
}


// Reset encoders
void reset()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
}

// Drive a distance at a ratio, to a set power level
void drive(long nMotorRatio, long dist, long power)
{
		float rotations = 360 * (dist / circumfrance);

		reset();

		setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, rotations, power);
		waitUntilMotorStop(leftMotor);
}
