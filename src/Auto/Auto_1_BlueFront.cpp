#include "main.h"
#include "MainConfig.h"

void auto_1()
{

  skidBase.setMaxVelocity(175);
  pros::delay(200);

  m_intake.move(127);

  skidBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  m_intake.move(0);

  skidBase.moveDistance(-39_in);
  pros::delay(100);

  skidBase.turnAngle(90_deg);
  pros::delay(100);

  skidBase.moveDistance(10_in);
  pros::delay(100);

  m_puncher.move_relative(-2700, 200);
  pros::delay(500);

  skidBase.moveDistance(16_in);
  pros::delay(100);

  skidBase.setMaxVelocity(100);

  skidBase.turnAngle(-10_deg);
  pros::delay(100);

  m_intake.move_relative(1800, 200);

  m_puncher.move_relative(-2700, 200);
  pros::delay(500);

  skidBase.turnAngle(10_deg);
  pros::delay(100);

  skidBase.moveDistance(22_in);
  pros::delay(100);
}
