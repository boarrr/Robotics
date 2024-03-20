#define leftMotor 1
#define rightMotor 2

void turn90(char direction);
int* input();
int go_to_x(int x, int curX);
int go_to_y(int y, int curY);

// Starting Position
int curX = 1;
int curY = 4;

task main()
{
	
	SensorType[S3] = sensorEV3_Color;
	SensorType[S4] = sensorEV3_Gyro;
	
	// target1 coordinates in {x,y}
	int *target;	
	int detected = 0;
	
	// Get target from user input
	target = input();
	
	// Go to the target coordinates
	curX = go_to_x(target[0], curX);
	curY = go_to_y(target[1], curY);
	
}


// Function to go to an X coordinate
int go_to_x(int x, int curX)
{
	int detected = 0;
	
	// If the current X is less than the target
	if (curX < x)
	{
		// Go there
		while (curX <= x)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", curX, curY);
			
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
	
	return curX;
}

// Function to go to a y coordinate
int go_to_y(int y, int curY)
{
	int detected = 0;
	
	// If current y is greater than the target y
	if (curY > y)
	{
		// turn left 90 degrees
		turn90('L');
		
		// drive until curY = target y
		while (curY >= y)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", curX, curY);
			
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
	// Otherwise, it is less than, turn right
	else if (curY < y)
	{
		turn90('R');
		
		// Drive until target
		while (curY <= y)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", curX, curY);
			
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
	
	return curY;
}


// Take user input and return coordinates as an array
int* input()
{
	int temp_target[2] = {0, 0};
	
	
	while(getButtonPress(buttonEnter) == 0)
	{
		displayBigTextLine(4, "Target: {	%d, %d}", temp_target[0], temp_target[1]);
		
		// Choosing target
		if (getButtonPress(buttonUp))
		{
			temp_target[1] += 1;
			sleep(80);
		}
		else if (getButtonPress(buttonDown))
		{
			temp_target[1] -= 1;
			sleep(80);
		}
		else if (getButtonPress(buttonLeft))
		{
			temp_target[0] -= 1;
			sleep(80);
		}
		else if (getButtonPress(buttonRight))
		{
			temp_target[0] += 1;
			sleep(80);
		}
	}
	
	return temp_target;
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
