#define leftMotor 1
#define rightMotor 2

void turn90(char direction);

task main()
{
	// Starting coordinates in {x, y}, facing x
	const int start[2] = {1,4};
	int curX = start[0];
	int curY = start[1];
	char curDirection = 'x';
	
	SensorType[S3] = sensorEV3_Color;
	SensorType[S4] = sensorEV3_Gyro;
	
	// target1 coordinates in {x,y}
	int target1[2] = {6,5};
	int detected = 0;
	
	if (curX < target1[0])
	{
		while (curX <= target1[0])
		{
			displayBigTextLine(4, "{	%d, %d}", curX, curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					curX++;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
		curX--;
	}
	
	
	if (curY > target1[1])
	{
		// turn left 90 degrees
		turn90('L');
		
		// drive until curY = target1[y]
		
		while (curY >= target1[1])
		{
			displayBigTextLine(4, "{	%d, %d}", curX, curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					curY--;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
	}
	else if (curY < target1[1])
	{
		turn90('R');
		
		while (curY <= target1[1])
		{
			displayBigTextLine(4, "{	%d, %d}", curX, curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					curY++;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
	}
}


// char 'L' for left turn, char 'R' for right turn
void turn90(char direction)
{
	// Reset gyro to 0
	resetGyro(S4);
	
	// Check direction for rotation, if L turn left
	if (direction == 'l'  || direction == 'L')
	{
		
		// Turn until 90 degrees to the left
		while(SensorValue[S4] < 80)
		{
			setMotorSync(leftMotor, rightMotor, 100, 100);
		}
		
	}
	// If Direction is R, turn right
	else if (direction == 'r'  || direction == 'R')
	{
		
		// Turn until 90 degrees to the right
		while(SensorValue[S4] > -80)
		{
			setMotorSync(leftMotor, rightMotor, -100, 100);
		}
		
	}
}