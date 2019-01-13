#include "main.h"
#include "MainConfig.h"
#include "Driver/Puncher_States.h"

double distanceFromFlag1 = 0;
double distanceFromFlag2 = 0;
double distanceFromFlagCalc = 0;

double distanceFromFlag = 0;
double desianglehigh = 0;
double desianglemedium = 0;

void driverControlTask(void*)
{

  while(true)
  {

//------------------manual controls------------------------------
    if (HIDMain.getDigital(ControllerDigital::R1))
    {
      // if (puncherPIDController.isDisabled() = false)
      // {
      // puncherPIDController.flipDisable();
      // m_puncher.move(-127);
      // }
      m_puncher.move(-127);
    }

    else if (HIDMain.getDigital(ControllerDigital::R2))
    {
      // if (puncherPIDController.isDisabled() = false)
      // {
      // puncherPIDController.stop();
      // }
      m_puncher.move(-127);
    }

    if (HIDMain.getDigital(ControllerDigital::L1))
    {
      m_intake.move(127);
    }

    if (HIDMain.getDigital(ControllerDigital::L2))
    {
      m_intake.move(-127);
    }
//------------------manual controls------------------------------

    if (HIDMain.getDigital(ControllerDigital::A))
    {
      shootFlagFunction();
    }

    else if (HIDMain.getDigital(ControllerDigital::X))
    {
      movetoMidFlagFunction();
    }

    else if (HIDMain.getDigital(ControllerDigital::Y))
    {
      movetoMidFlagFunction();
    }

    else
    {
      m_puncher.move(0);
      m_intake.move(0);
    }
  }
}
