#include "main.h"
#include "MainConfig.h"

#include "Auto/Shared_Auto/Auto_Selector.h"

void auto_0();
// void auto_1();
// void auto_2();
// void auto_3();
// void auto_4();
// void auto_5();

okapi::ChassisControllerIntegrated skidBase = ChassisControllerFactory::create(
  {-e_frontLeft,-e_rearLeft} ,{e_frontRight,e_rearRight},
  //IterativePosPIDController::Gains{0.0, 0, 0}, //distance PID
  //IterativePosPIDController::Gains{0.0, 0.00, 0}, //Angle PID
  //IterativePosPIDController::Gains{0.0, 0, 0}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 11.75_in}
);



//--------------Initialize--------------------------------------------
void initialize()
{
pros::Task DriverControl(driverControlTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "driverControlTask" );
//pros::Task AutoSelect(autoSelectTask, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "autoSelectTask" );
pros::Task Puncher(puncherTasks, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "autoSelectTask" );

s_encoder.reset();

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

auto_0();

//  if (int_auto_select == 1)
//  {
//    auto_1();
//  }
//  else if (int_auto_select == 2)
//  {
//    auto_2();
//  }
//  else if (int_auto_select == 3)
//  {
//    auto_3();
//  }
//  else if (int_auto_select == 4)
//  {
//    auto_4();
//  }
//  else if (int_auto_select == 5)
//  {
//    auto_5();
//  }
 }

//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  while(true)
  {
    baseControlFunction();
    pros::delay(20);
  }
}

//------------opControl------------------------------------------------
