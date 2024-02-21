#pragma config(Sensor, S1,     ultraSonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     lightSensor,    sensorEV3_Color)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void lineTrack();

task main()
{
	lineTrack();
}

void lineTrack()
{
	while(1)
	{
		// Exit program if enter is pressed
		displayBigTextLine(4, "Enter to end");
		if(getButtonPress(buttonEnter) == 1) stopAllTasks();

		// Turn left if dark detected, else turn right
		if(SensorValue(lightSensor) < 25)
		{
    	setMotorSync(leftMotor, rightMotor, -25, 25);
    }
    else
    {
    	setMotorSync(leftMotor, rightMotor, 25, 25);
    }
  }
}