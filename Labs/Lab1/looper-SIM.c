

/*	This is a sample Program
	Use File->Load C Prog to
	load a different Program
*/

task main()
{
	int time = 10000;	
	
	setMotorSpeed(1, 50);
	setMotorSpeed(2, -50);
	
	sleep(275);
	
	setMotorSpeed(1, 35);
	setMotorSpeed(2, 50);
	
	sleep(time);
	
	setMotorSpeed(1, -50);
	setMotorSpeed(2, 50);
	
	sleep(275);

}
