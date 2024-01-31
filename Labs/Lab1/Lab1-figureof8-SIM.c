

task main()
{
	// Turn 90 degrees to the left
	setMotorSpeed(1, 50);
	setMotorSpeed(2, -50);
	
	sleep(410);
	
	setMotorSpeed(1, 25);
	setMotorSpeed(2, 50);
	
	sleep(6000);
	
	setMotorSpeed(1, 50);
	setMotorSpeed(2, 25);
	
	sleep(6000);
	
	setMotorSpeed(1, -50);
	setMotorSpeed(2, 50);
	
	sleep(410);

}
