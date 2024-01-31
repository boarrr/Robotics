void moveRobot(long nMotorRatio, long time, long power);
void randomDirection();

task main()
{

	// Task 5A
	moveRobot(0, 1000, 50); // Go forward 1 second
	sleep(100);

	moveRobot(50, 875, 50); // Turn right
	sleep(100);

	moveRobot(-50, 875, 50); // Turn left to reset position
	sleep(100);

	playTone(500, 100);
	sleep(1500);


	// Task 5B
	for(int i = 0; i < 3; i++)
	{
		randomDirection();
		sleep(250);
	}

	playTone(500, 100);
	sleep(1500);


	// Task 6A
	for(int i = 0; i < 4; i++)
	{
		moveRobot(0, 3000, 50);
		sleep(100);
		moveRobot(50, 875, 50);
	}

	playTone(500, 100);
	sleep(1500);


	// Task 6B
	moveRobot(0, 2000, 50);
	sleep(100);
	moveRobot(50, 1700, 50);
	sleep(100);
	moveRobot(0, 5000, 25);
}


void moveRobot(long nMotorRatio, long time, long power)
{
		setMotorSyncTime(motorB, motorC, nMotorRatio, time, power);
		sleep(time);
}

void randomDirection()
{
		int num = random(1);

		if (num == 0)
		{
			moveRobot(50, 1000, 50);
		}
		else
		{
			moveRobot(-50, 1000, 50);
		}
}
