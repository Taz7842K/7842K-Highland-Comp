#include "main.h"
#include "MainConfig.h"




extern void baseControlTask(void*);
extern void driverControlTask(void*);



//--------------Initialize--------------------------------------------
void initialize()
{
  pros::delay(500);
  s_intakeLight.calibrate();
  s_light.calibrate();
  m_puncherAim.tare_position();
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
  // if(s_autoSelect.get_value() < 819){auto_0();}
  //
  // else if(s_autoSelect.get_value()> 819 && s_autoSelect.get_value() < 1638){auto_1();}
  //
  // else if(s_autoSelect.get_value()> 1638 && s_autoSelect.get_value() < 2457){auto_2();}
  //
  // else if(s_autoSelect.get_value()> 2457 && s_autoSelect.get_value() < 3276){auto_3();}
  //
  // else if(s_autoSelect.get_value()> 3276 && s_autoSelect.get_value() < 4095){auto_4();}

  auto_1();

}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  while(true)
  {
  std::cout << "autoselector value = " <<s_autoSelect.get_value()<<std::endl;
  std::cout << "distance calculated: " << distancefromflag << std::endl;
  std::cout << "medium angle :" << desianglemedium << std::endl;
  std::cout << "high angle: " << desianglehigh << std::endl;
  std::cout << "angle sensor value: " << enc_puncher << std::endl;

  std::cout << "lightvalue = " << s_light.get_value_calibrated() << std::endl;
  std::cout << "intakelightvalue = " << s_intakeLight.get_value_calibrated() << std::endl;

    calcFlagDistance();
    calcAngle();
    baseControlTask();
    intakeTask();
    driverControlTask();

    pros::delay(70);
}
}
//------------opControl------------------------------------------------
