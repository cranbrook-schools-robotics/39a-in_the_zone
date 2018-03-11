#pragma config(UserModel, "39AConfig.c")
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
#include <CKTankDrive.h>

tMotor leftDriveMotors[] = {rLBase,mLBase,fLBase};
tMotor rightDriveMotors[] = {rRBase,mRBase,fRBase};
tMotor leftDriveMotorsWithMogo[] = {rLBase};
tMotor rightDriveMotorsWithMogo[] = {rRBase};

TankDrive driveTrain;
TankDrive driveTrainWithMogo;


void pre_auton()
{
	bStopTasksBetweenModes = true;
}

task autonomous()
{
	TankDriveInit(driveTrain, leftDriveMotors, rightDriveMotors, 3, leftSideEncoder, rightSideEncoder, gyro, 4, 0.0085, 0.0, 0.0, 15,40 );
	TankDriveInit(driveTrainWithMogo, leftDriveMotorsWithMogo, rightDriveMotorsWithMogo, 1, leftSideEncoder, rightSideEncoder, gyro, 4, 0.0085, 0.0, 0.0, 15,40 );
}

task usercontrol()
{
	float threshold = 10;
	while (true)
	{

		if(vexRT[Btn6U] || vexRT[Btn6D])
		{
				//motor[fLBase] = vexRT[Btn6U] ? -127 : (vexRT[Btn6D] ? 127 : 0);
				//motor[mLBase] = vexRT[Btn6U] ? 127 : (vexRT[Btn6D] ? -127 : 0);
				//motor[fRBase] = vexRT[Btn6U] ? -127 : (vexRT[Btn6D] ? 127 : 0);
				//motor[mRBase] = vexRT[Btn6U] ? 127 : (vexRT[Btn6D] ? -127 : 0);
				setDriveTank(driveTrainWithMogo, threshold);
		}
		//else
			setDriveTank(driveTrain,threshold);
	}
}
