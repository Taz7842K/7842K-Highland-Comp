#include "main.h"
#include "Puncher_States"

void movetoHighFlagFunction()
{
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
};

void shootHighFlagFunction()
{
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
};

void movetoMidFlagFunction()
{
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
};

void shootMidFlagFunction()
{
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
};
