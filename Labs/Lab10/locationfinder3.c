#define leftMotor 1
#define rightMotor 2

void turn90(char direction);
void go_target_1(int *curX, int *curY);
void go_target_2(int *curX, int *curY);
int go_to_x(int x, int *curX);
void go_to_y(int y, int *curY);
void update_coord(int *curr, int change);
void face_dir(int dir, int curr);
void set_stop();
void wait_beep();



// Starting Position
int curX = 3;
int curY = 1;

// Cardinal Coordinates, 0 for North, 1 for East, 2 for South, 3 for West
int start_dir = 1;
int curr_dir = 1;


task main()
{
	
	SensorType[S3] = sensorEV3_Color;
	SensorType[S4] = sensorEV3_Gyro;
	
	go_target_1(&curX, &curY);
	
	// Set motors to 0, for an unusual bug fix
	set_stop();
	
	wait_beep();
	
	go_target_2(&curX, &curY);
}


void go_target_1(int *curX, int *curY)
{
	int target1[2] = {3, 7};
	
	go_to_x(target1[0], curX);
	set_stop();
	sleep(100);
	go_to_y(target1[1], curY);
	
}

void go_target_2(int *curX, int *curY)
{
	int target1[2] = {1, 1};
	
	go_to_x(target1[0], curX);
	set_stop();
	sleep(100);
	go_to_y(target1[1], curY);
	
}

// Function to go to an X coordinate
int go_to_x(int x, int *curX)
{
	int detected = 0;
	
	if (*curX == x)
		return 0;
	
	// If the current X is less than the target
	if (*curX > x)
	{
		face_dir(3, curr_dir);
		
		// Go there
		while (*curX >= x)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", *curX, curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					(*curX)--;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
		(*curX)++;
	}
	else 
	{
		face_dir(1, curr_dir);
		
		// Go there
		while (*curX <= x)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", *curX, curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					(*curX)++;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
		*(curX)--;
	}
	
	return 0;
}


// Function to go to a y coordinate
void go_to_y(int y, int *curY)
{
	int detected = 0;
	
	// If current y is greater than the target y
	if (*curY > y)
	{
		
		// Turn based on current facing direction
		if (curr_dir == 1)
			turn90('L');
		else
			turn90('R');
		
		
		
		// drive until curY = target y
		while (*curY >= y)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", curX, *curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					(*curY)--;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
		(*curY)++;
	}
	// Otherwise, it is less than, turn right
	else if (*curY < y)
	{
		// Turn based on current facing direction
		if (curr_dir == 1)
			turn90('R');
		else
			turn90('L');
		
		// Drive until target
		while (*curY <= y)
		{
			displayBigTextLine(6, "Current: {	%d, %d}", curX, *curY);
			
			if (SensorValue[S3] > 25) 
			{
				detected = 0;
			}
			else
			{
				if (detected == 0)
				{
					(*curY)++;
				}
				
				detected = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		
		(*curY)--;
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
		
		
		update_coord(&curr_dir, -1);
	}
	// If Direction is R, turn right
	else if (direction == 'r'  || direction == 'R')
	{
		
		// Turn until 90 degrees to the right
		while(SensorValue[S4] > -80)
		{
			setMotorSync(leftMotor, rightMotor, -100, 100);
		}
		
		update_coord(&curr_dir, 1);
	}
}

void update_coord(int *curr, int change)
{
	// Four directions, mod(4) to ensure it wraps around
	*curr = (*curr + change) % 4;
	
	// If negative, wrap up to 3 again
	if (*curr < 0)
		*curr += 4;
}

void face_dir(int dir, int curr)
{
	while (curr < dir) {
		turn90('r');
		curr++;
	}
	
	while (curr > dir) {
		turn90('l');
		curr--;
	}
}

void wait_beep()
{
	for (int i = 0; i < 5; i++) 
	{
		playTone(1000, 1000);
		sleep(1000);
	}
	
}

void set_stop()
{
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}