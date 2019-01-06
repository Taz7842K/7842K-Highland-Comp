#include "main.h"
#include "MainConfig.h"

pros::Controller HIDMain(pros::E_CONTROLLER_MASTER);


void setBasePower(int xPower, int yPower, int zPower)
{
  m_frontLeft.move(yPower-xPower-zPower);
	m_rearRight.move(yPower+xPower-zPower);
	m_frontRight.move(yPower+xPower+zPower);
  m_rearLeft.move(yPower-xPower+zPower);
}

void baseControlTask(void*)
{

  while(true)
  {

    setBasePower(HIDMain.get_analog(ANALOG_LEFT_X), -HIDMain.get_analog(ANALOG_RIGHT_Y), HIDMain.get_analog(ANALOG_RIGHT_X));
    pros::delay(20);
  }
}

// remove error your problem
// telllletype
