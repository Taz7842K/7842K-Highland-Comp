#include "main.h"
#include "MainConfig.h"
#include "Auto/AutoConfig.h"

void auto_1()
{
  skidBase.setMaxVelocity(movMaxVel);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(400);               //pause to intake ball

  // while(s_intakeLight.get_value_calibrated() > -4){pros::delay(20);}

  m_intake.move(0);
  pros::delay(movDel);

  skidBase.moveDistance(-45_in);
  pros::delay(movDel);

  skidBase.moveDistance(8_in);
  pros::delay(movDel);

  skidBase.turnAngle(98_deg);
  pros::delay(movDel);

  skidBase.moveDistance(30_in);
  pros::delay(movDel);

  while(s_light.get_value_calibrated() > -90)
  {
    m_intake.move(127);
  }
  m_intake.move(0);

  m_intake.move_relative(-1350,127);
  pros::delay(1000);

  m_puncher.move_relative(-3000, 200);
  pros::delay(1300);
  //
  // skidBase.moveDistance(_in);
  // pros::delay(movDel);

  skidBase.setMaxVelocity(100);
  //
  // while(s_light.get_value_calibrated() > -200)
  // {
  //   m_intake.move(127);
  // }
  // m_intake.move(0);
  //
  // m_puncher.move_relative(-3000, 200);
  // pros::delay(1300);

  skidBase.turnAngle(10_deg);
  pros::delay(movDel);

  skidBase.moveDistance(22_in);
  pros::delay(movDel);
}
