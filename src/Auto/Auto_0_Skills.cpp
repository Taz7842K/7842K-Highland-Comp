#include "main.h"
#include "MainConfig.h"


void auto_0()
{
  skidBase.setMaxVelocity(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  m_intake.move(0);

  skidBase.moveDistance(-39_in);
  pros::delay(100);

  skidBase.turnAngle(90_deg);
  pros::delay(100);

  skidBase.moveDistance(18_in);
  pros::delay(100);

  skidBase.moveDistance(22_in);

  skidBase.moveDistance(-50);

}
