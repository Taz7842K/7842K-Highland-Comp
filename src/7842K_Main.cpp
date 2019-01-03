#include "main.h"
#include "MainConfig.h"

Motor frontRight(2);
Motor frontLeft(3);
Motor rearRight(4);
Motor rearLeft(5);


XDriveModel(, frontLeft, rearRight, rearLeft, 200, 12000);


//--------------Initialize--------------------------------------------
void initialize()
{
pros::Task BaseControl(baseControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "baseControlTask" );
pros::Task DriverControl(driverControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "driverControlTask" );
}
//const int puncher(6);


// -------------Initialize---------------------------------------------

//--------------Disabled-----------------------------------------------
void disabled() {}
//--------------Disabled-----------------------------------------------

//--------------Competition Initialize---------------------------------
void competition_initialize() {}
//--------------Competition Initialize---------------------------------

//--------------Autonomous---------------------------------------------
void autonomous()
{

}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{

}

//------------opControl------------------------------------------------
