#pragma config(Sensor, S1,     ultraSonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     lightSensor,    sensorEV3_Color)
#pragma config(Sensor, S3,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


// Wheel circumfrance = 17.6cm
#define circumfrance 17.6


// Function prototypes
int getDistance();
void square(int dist);
void reset();
void drive(int dist, int pow);
void turn90();


task main()
{
	int distance = getDistance();

	square(distance);
}


// Gets distance from user
int getDistance()
{
	// Default distance
	int distance = 10;


	// While user has not selected
	while(getButtonPress(buttonEnter) == 0)
	{
		// Display current selection
		displayBigTextLine(4, "%d cm perimeter", distance);

		// Choosing distance
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

	return distance;
}


void square(int dist)
{
	// Loop for each side of a square (4 times)
	for (int i = 0; i < 4; i++)
	{
		// Drive forward set distance
		drive(dist, 25);

		// Turn 90 degrees
		turn90();
	}
}


void turn90()
{
	// Reset gyro to 0
	resetGyro(gyroSensor);

	// Turn until 90 degrees, 85 set due to accuracy issues
	while(SensorValue[gyroSensor] < 85)
	{
		setMotorSync(leftMotor, rightMotor, 100, 25);
	}
}


void drive(int dist, int pow)
{
	// Number of rotations needed to go set distance
	float rotations = 360 * (dist / circumfrance);

	// Drive until the encoder hits set rotations
	reset();
	setMotorSyncEncoder(leftMotor, rightMotor, 0, rotations, 25);
	waitUntilMotorStop(leftMotor);
}


// Reset encoders to 0
void reset()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
}