#include "main.h"
#include "auto/auto_config.h"

void auto_0(void*)
{

  mecBase.setmaxVelocity(200);
  pros::delay(100);

  ballshoot();

  mecBase.turnAngle(90_deg);
  pros::delay(100);

  mecBase.moveDistance(40_in);
  pros::delay(100);

  mecBase.moveDistance()

}
