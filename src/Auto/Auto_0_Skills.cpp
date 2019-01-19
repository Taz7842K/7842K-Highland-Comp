#include "main.h"
#include "MainConfig.h"
#include "Auto/AutoConfig.h"


void auto_0()
{
  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(43_in);
             //pause to intake ball

  while(s_intakeLight.get_value_calibrated() > -4){pros::delay(20);}

  m_intake.move(0);

  skidBase.moveDistance(-48_in);
  pros::delay(movDel);

  skidBase.moveDistance(2_in);
  pros::delay(movDel);

  skidBase.turnAngle(-100_deg);
  pros::delay(225);

  skidBase.moveDistance(51_in);
  pros::delay(movDel);


  skidBase.setMaxVelocity(75);
  pros::delay(100);

  skidBase.turnAngle(-13_deg);
  pros::delay(movDel);

  m_puncher.move_relative(-2700,200);
  pros::delay(2000);

  while(s_light.get_value_calibrated() > -300)
  {
    m_intake.move(127);
  }
  m_intake.move(0);

  skidBase.moveDistance(23_in);
  pros::delay(movDel);

  while(s_light.get_value_calibrated() > -300)
  {
    m_intake.move(127);
  }
  m_intake.move(0);

  m_puncher.move_relative(-2700,200);
  pros::delay(2000);

  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(100);

  skidBase.moveDistance(22_in);
  pros::delay(movDel);

  skidBase.moveDistance(-48_in);
  pros::delay(movDel);

  skidBase.turnAngle(90_deg);
  pros::delay(movDel);

  skidBase.moveDistance(-7_in);
  pros::delay(movDel);
}
