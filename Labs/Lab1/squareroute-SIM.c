

/*	This is a sample Program
	Use File->Load C Prog to
	load a different Program
*/

task main()
{
	int time = 4000;
	int count = 4;
	
	setMotorSpeed(1, 50);
	setMotorSpeed(2, -50);
	
	sleep(410);
	
	while(count > 0)
	{
		
		setMotorSpeed(1, 50);
		setMotorSpeed(2, 50);
		
		sleep(time);
		
		setMotorSpeed(1, -50);
		setMotorSpeed(2, 50);
		
		sleep(410);
		
		count = count - 1;
		
	}
	
	setMotorSpeed(1, -50);
	setMotorSpeed(2, 50);
	
	sleep(410);

}
