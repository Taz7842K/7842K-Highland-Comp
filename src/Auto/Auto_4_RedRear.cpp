#include "main.h"
#include "MainConfig.h"
#include "Auto/AutoConfig.h"

void auto_4()
{
  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(700);               //pause to intake ball

  // while(s_intakeLight.get_value_calibrated() > -4){pros::delay(20);}

  m_intake.move(0);
  pros::delay(movDel);

  skidBase.moveDistance(-10_in);
  pros::delay(movDel);

  skidBase.turnAngle(270_deg);
  pros::delay(movDel);

  skidBase.moveDistance(16_in);
  pros::delay(movDel);

}
