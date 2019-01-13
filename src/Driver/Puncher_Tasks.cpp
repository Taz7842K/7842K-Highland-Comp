#include "main.h"
#include "MainConfig.h"
#include "Driver/Puncher_States.h"




void puncherTasks(void*)
{
  while(true)
  {
    double distanceFromFlag1 = s_ultrasonic1.get_value();
    double distanceFromFlag2 = s_ultrasonic2.get_value();

    double distancefromflag = (((distanceFromFlag1/2.54)/10 + 6)); //outputs in inches and adds distance from sensor to pivot point
    double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
    double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));  //outputs in degrees and subtracts starting angle

  }
}
