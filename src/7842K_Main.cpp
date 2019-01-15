#include "main.h"
#include "MainConfig.h"




extern void baseControlTask(void*);
extern void driverControlTask(void*);


okapi::ChassisControllerIntegrated skidBase = ChassisControllerFactory::create(
  {e_frontLeft,e_rearLeft} ,{e_frontRight,e_rearRight},

  AbstractMotor::gearset::green,
  {4_in, 11.75_in}
);

//--------------Initialize--------------------------------------------
void initialize()
{

}

//const int puncher(6);


// -------------Initialize---------------------------------------------

//--------------Disabled-----------------------------------------------
void disabled()
{

}
//--------------Disabled-----------------------------------------------

//--------------Competition Initialize---------------------------------
void competition_initialize() {}
//--------------Competition Initialize---------------------------------

//--------------Autonomous---------------------------------------------
void autonomous()
{
  auto_1();
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
//   while(true)
//   {
//   double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));
//
//   double desianglehigh = (atanf(38.8/distancefromflag)*(180/pi));
//   double desianglemedium = (atanf(24.4/distancefromflag)*(180/pi));
//
//   std::cout << "distance:" << distancefromflag << std::endl;
//   std::cout << "medium angle:" << desianglemedium << std::endl;
//   std::cout << "high angle:" << desianglehigh << std::endl;
//   std::cout << "angle sensor value:" << s_encoder.get_value() << std::endl;
//
//   pros::delay(200);
// }

  while(true)
  {
    baseControlTask();
    driverControlTask();

    pros::delay(20);
  }
}
//------------opControl------------------------------------------------
