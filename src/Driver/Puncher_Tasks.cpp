#include "main.h"
#include "Driver/Puncher_States.h"
#include"MainConfig.h"

//m_puncher.setPosPID(0.2,0,0,0);

void movetoHighFlagFunction()
{

     m_puncher.move_relative(desianglehigh * 2.5 - s_encoder.get_value(), 70);              // changes angle to encoder units and subtracts current value
     pros::delay(10);

   m_puncher.move(0);
   pros::delay(10);
}

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

}

void movetoMidFlagFunction()
{
  while(s_encoder.get_value()<37.5-(desianglemedium))
    {
      m_puncher.move_relative(desianglehigh * 2.5 - s_encoder.get_value(), 70);
      pros::delay(10);
    }
    m_puncher.move(0);
    pros::delay(10);

}

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
}
