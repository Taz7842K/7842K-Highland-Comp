#include "main.h"
#include "MainConfig.h"




extern void baseControlTask(void*);
extern void driverControlTask(void*);



//--------------Initialize--------------------------------------------
void initialize()
{
  pros::delay(500);
  s_intakeLight.calibrate();
  s_light.calibrate();                    //calibrates while BALL IS IN THE PUNCHER
  pros::delay(500);
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
  auto_0();
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  while(true)
  {

  std::cout << "distance calculated: " << distancefromflag << std::endl;
  std::cout << "medium angle :" << desianglemedium << std::endl;
  std::cout << "high angle: " << desianglehigh << std::endl;
  std::cout << "angle sensor value: " << s_encoder.get_value() << std::endl;

  std::cout << "lightvalue = " << s_light.get_value_calibrated() << std::endl;

  pros::delay(200);
}
}
//   while(true)
//   {
//     baseControlTask();
//     driverControlTask();
//
//     pros::delay(20);
//   }
// }
//------------opControl------------------------------------------------
