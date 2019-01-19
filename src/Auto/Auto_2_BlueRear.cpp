#include "main.h"
#include "MainConfig.h"
#include "Auto/AutoConfig.h"

void auto_1()
{
  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  while(s_intakeLight.get_value_calibrated() > -4){pros::delay(20);}

  m_intake.move(0);
  pros::delay(movDel);

  skidBase.moveDistance(-20_in);
  pros::delay(movDel);

  skidBase.turnAngle(90_deg);
  pros::delay(movDel);

  skidBase.moveDistance(20_in);
  pros::delay(movDel);

}
