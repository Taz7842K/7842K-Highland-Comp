#include "main.h"
#include "Auto/Auto_Config.h"
#include "Driver/Puncher_States.h"

void auto_0(void*)
{

  puncherSwitch = true;

  mecBase.setMaxVelocity(200);
  pros::delay(100);

  om_intake.move(127);

  mecBase.moveDistance(40_in);
  pros::delay(500);               //pause to intake ball

  om_intake.move(0);

  mecBase.moveDistance(-39_in);
  pros::delay(100);

  mecBase.turnAngle(90_deg);
  pros::delay(100);

  mecBase.moveDistance(18_in);
  pros::delay(100);

  movetoHighFlagFunction();
  shootHighFlagFunction();
  movetoMidFlagFunction();
  shootMidFlagFunction();

  mecBase.moveDistance(22_in);

  mecBase.moveDistance(-50);


}
