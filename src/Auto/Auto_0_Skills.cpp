#include "main.h"
#include "Auto/Auto_Config.h"
#include "Driver/Puncher_States.h"

void auto_0()
{

  skidBase.setMaxVelocity(200);
  pros::delay(100);

  m_intake.moveVelocity(200);

  skidBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  m_intake.move(0);

  skidBase.moveDistance(-39_in);
  pros::delay(100);

  skidBase.turnAngle(90_deg);
  pros::delay(100);

  skidBase.moveDistance(18_in);
  pros::delay(100);

  movetoHighFlagFunction();
  shootFlagFunction();
  movetoMidFlagFunction();
  shootFlagFunction();

  while(distanceFromFlag1 > 100)
  {
  skidBase.moveDistance(.1_in);
  }

  skidBase.moveDistance(-50_in);
  pros::delay(100);

  skidBase.turnAngle(90_deg);
  pros::delay(100);

  skidBase.moveDistance(-7_in);                   //moves backward to center against wall
  pros::delay(100);

  m_intake.moveVelocity(200);

  skidBase.moveDistance(42_in);
  pros::delay(100);

  m_intake.moveVelocity(0);

  skidBase.moveDistance(0_in);
}
