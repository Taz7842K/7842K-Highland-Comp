#include "main.h"
#include "MainConfig.h"

#include "Auto/Shared_Auto/Auto_Selector.h"

Motor frontRight(2);
Motor frontLeft(3);
Motor rearRight(4);
Motor rearLeft(5);

okapi::XDriveModel mecBase_Model = ChassisModelFactory::create(frontRight, frontLeft, rearRight, rearLeft, 200, 1200);

okapi::ChassisControllerPID mecBase = ChassisControllerFactory::create(
  1,2,3,4,
  IterativePosPIDController::Gains{0.5, 0, 0}, //distance PID
  IterativePosPIDController::Gains{0.1, 0.05, 0}, //Angle PID
  IterativePosPIDController::Gains{0.2, 0, 0}, //turning PID
  AbstractMotor::gearset::green,
  {2.75_in, 10.5_in}
);


//--------------Initialize--------------------------------------------
void initialize()
{
pros::Task BaseControl(baseControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "baseControlTask" );
pros::Task DriverControl(driverControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "driverControlTask" );
pros::Task AutoSelect(autoSelectTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "autoSelectTask" );
}


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
 if (int_auto_select == 1)
 {
   auto_1();
 }
 else if (int_auto_select == 2)
 {
   auto_2();
 }
 else if (int_auto_select == 3)
 {
   auto_3();
 }
 else if (int_auto_select == 4)
 {
   auto_4();
 }
 else if (int_auto_select == 5)
 {
   auto_5();
 }
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{

}

//------------opControl------------------------------------------------
