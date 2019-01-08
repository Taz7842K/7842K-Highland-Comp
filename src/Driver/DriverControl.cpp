#include "main.h"
#include "MainConfig.h"

pros::ADIUltrasonic s_ultrasonic1(11,12); //PLACEHOLDER!!!
pros::ADIUltrasonic s_ultrasonic2(13,14); //PLACEHOLDER!!!

double distanceFromFlag1 = 0;
double distanceFromFlag2 = 0;
double distanceFromFlagCalc = 0;

bool puncherSwitch = false;

enum puncher_states
{
  doNothing,
  movetoMidFlag,
  shootHighFlag,
  movetoHighFlag,
  shootMidFlag
};
puncher_states stateofPuncher = doNothing;

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

void ballshoot(void*)
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

   while(s_encoder.get_value()<40.5-(desianglehigh))
    {
      m_puncher.move_velocity(60);
      pros::delay(10);
    }

    m_puncher.move(0);
    pros::delay(10);
    if (puncherSwitch == true)
    {
      stateofPuncher = shootHighFlag;
    }
break;

case shootHighFlag:

  while(s_light.get_value_calibrated()>-100)
  {
    m_intake.move(127);
    m_puncher.move(-127);
    pros::delay(10);
  }
    m_intake.move(-127);
    m_puncher.move(-127);
    pros::delay(100);

    m_intake.move(0);
    pros::delay(10);

    m_puncher.move(-127);
    pros::delay(750);

    m_puncher.move(0);
    pros::delay(10);

    if (puncherSwitch == true)
    {
      stateofPuncher = movetoMidFlag;
    }
break;

case movetoMidFlag:

  while(s_encoder.get_value()<37.5-(desianglemedium))
    {
      m_puncher.move(50);
      pros::delay(10);
    }
    m_puncher.move(0);
    pros::delay(10);
if (puncherSwitch == true)
{
  stateofPuncher = shootMidFlag;
}
break;

case shootMidFlag:

  while(s_light.get_value_calibrated()>-100)
  {
    m_intake.move(127);
    m_puncher.move(-127);
    pros::delay(10);
  }
  m_intake.move(-127);
  m_puncher.move(-127);
  pros::delay(250);

  m_intake.move(0);
  pros::delay(10);

  m_puncher.move(-127);
  pros::delay(1000);

  m_puncher.move(0);
  pros::delay(10);

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
