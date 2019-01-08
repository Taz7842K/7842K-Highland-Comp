#include "main.h"
#include "MainConfig.h"
#include "Driver/Puncher_States.h"

pros::ADIUltrasonic s_ultrasonic1(11,12); //PLACEHOLDER!!!
pros::ADIUltrasonic s_ultrasonic2(13,14); //PLACEHOLDER!!!

double distanceFromFlag1 = 0;
double distanceFromFlag2 = 0;
double distanceFromFlagCalc = 0;

bool puncherSwitch = false;

void calc_FlagDistance(double distanceFromFlag1, double distancefromFlag2)
{
  if (distanceFromFlag1 < 5)
  {
    distanceFromFlagCalc = distanceFromFlag2;
  }

  if (distanceFromFlag2 < 5)
  {
    distanceFromFlagCalc = distanceFromFlag1;
  }

  else
  {
    distanceFromFlagCalc = (distanceFromFlag1 + distanceFromFlag2) /2;
  }

}

void puncherTasks(void*)
{
  while(true)
  {
    double distanceFromFlag1 = s_ultrasonic1.get_value();
    double distanceFromFlag2 = s_ultrasonic2.get_value();

    calc_FlagDistance(distanceFromFlag1, distanceFromFlag2);

    s_encoder.reset();

    double distancefromflag = (((distanceFromFlagCalc/2.54)/10));
    double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
    double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));

    std::cout << "distance:" << distancefromflag << std::endl;
    std::cout << "medium angle:" << desianglemedium << std::endl;

switch (stateofPuncher)
{
case doNothing:
break;

if (puncherSwitch == true)
{
  stateofPuncher = movetoHighFlag;
}

case movetoHighFlag:
movetoHighFlagFunction();
break;

case shootHighFlag:
shootHighFlagFunction();
break;

case movetoMidFlag:
movetoMidFlagFunction();
break;

case shootMidFlag:
shootMidFlagFunction();
break;
  }
}
}


void driverControlTask(void*)
{

  while(true)
  {

    if (HIDMain.get_digital(DIGITAL_R1))
    {
      m_puncher.move(-127);
    }

    else if (HIDMain.get_digital(DIGITAL_R2))
    {
      m_puncher.move(38);
    }
    else
    {
      m_puncher.move(0);
    }

    if (HIDMain.get_digital(DIGITAL_Y))
    {
      puncherSwitch = true;
    }

    if (HIDMain.get_digital(DIGITAL_X))
    {
      puncherSwitch = false;
    }
  }
}
