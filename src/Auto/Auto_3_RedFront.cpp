#include "main.h"
#include "MainConfig.h"
#include "Auto/AutoConfig.h"

void auto_3()
{
  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  while(s_intakeLight.get_value_calibrated() > -4){pros::delay(20);}

  m_intake.move(0);
  pros::delay(movDel);

  skidBase.moveDistance(-39_in);
  pros::delay(movDel);

  skidBase.turnAngle(-90_deg);
  pros::delay(movDel);

  skidBase.moveDistance(10_in);
  pros::delay(movDel);

  m_puncher.move_relative(-2700, 200);
  pros::delay(500);

  skidBase.moveDistance(16_in);
  pros::delay(movDel);

  skidBase.setMaxVelocity(100);

  skidBase.turnAngle(10_deg);
  pros::delay(movDel);

  m_intake.move_relative(1800, 200);

  m_puncher.move_relative(-2700, 200);
  pros::delay(500);

  skidBase.turnAngle(-10_deg);
  pros::delay(movDel);

  skidBase.moveDistance(22_in);
  pros::delay(movDel);
}
