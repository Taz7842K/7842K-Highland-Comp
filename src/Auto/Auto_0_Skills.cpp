#include "main.h"

void auto_0(void*)
{

  mecBase.setmaxVelocity(200);
  pros::delay(20);

  mecBase.moveDistance(5_in);
  pros::delay(20);

  mecBase.turnAngle(90_deg);

  ballshoot();
}
