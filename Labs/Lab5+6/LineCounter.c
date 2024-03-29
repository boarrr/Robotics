#pragma config(Sensor, S1,     ultraSonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     lightSensor,    sensorEV3_Color)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void driveUntilLine();

task main()
{
	driveUntilLine();
}

void driveUntilLine()
{
	int line = 0, detect = 0;

	while(1)
	{
		displayBigTextLine(4, "Enter to end");
		displayBigTextLine(7, "Lines: %d", line);

		if(getButtonPress(buttonEnter) == 1) stopAllTasks();

		if (SensorValue(lightSensor) > 20)
		{
			detect = 0;
			setMotorSync(leftMotor, rightMotor, 0, 20);
		}
		else
		{
			if (detect == 0) line++;
			detect = 1;

			setMotorSync(leftMotor, rightMotor, 0, 0);
			sleep(500);

			while(SensorValue(lightSensor) < 20)
			{
				if(getButtonPress(buttonEnter) == 1) stopAllTasks();

				setMotorSync(leftMotor, rightMotor, 0, 5);
			}
		}
	}
}
