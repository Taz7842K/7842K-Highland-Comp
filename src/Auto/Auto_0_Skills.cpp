#include "main.h"
#include "Auto/Auto_Config.h"
#include "Driver/Puncher_States.h"

void auto_0(void*)
{

  puncherSwitch = true;

  mecBase.setmaxVelocity(200);
  pros::delay(100);

  mecBase.moveDistance(40_in);
  pros::delay(100);



  movetoHighFlagFunction();
  shootHighFlagFunction();

  mecBase.turnAngle(90_deg);
  pros::delay(100);

  mecBase.moveDistance(40_in);
  pros::delay(100);

  mecBase.moveDistance(0);


}
