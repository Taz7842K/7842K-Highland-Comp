#include "main.h"
#include "MainConfig.h"

int master;

bool intakeSwitch = false;

const double _pi = 3.141592653589793238462643383279502886;

double distancefromflag;
double desianglehigh;
double desianglemedium;

void movetoMidFlag()
{

  s_encoder.reset();

  std::cout << "==================code has reached start==============================================" << master << std::endl;

  distancefromflag = (((calcFlagDistance()/2.54)/10 -10));

  desianglehigh = (atanf(38.8/distancefromflag)*(180/_pi));
  desianglemedium = (atanf(24.4/distancefromflag)*(180/_pi));

  std::cout << "distance:" << distancefromflag << std::endl;
  std::cout << "medium angle:" << desianglemedium << std::endl;
  std::cout << "high angle:" << desianglehigh << std::endl;
  std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;

  while(s_encoder.get_value()<35.5-(desianglehigh))
  {
    m_puncher.move(50);
    pros::delay(10);
  }


  std::cout << "==================code has reached first puncher aim==============================================" << master << std::endl;

  m_puncher.move(0);
  pros::delay(10);

  while(s_light.get_value_calibrated()>-50)
  {
    m_intake.move(127);
    pros::delay(10);
  }
  m_intake.move(-127);
  pros::delay(200);

  std::cout << "==================code has reached first ball intook==============================================" << master << std::endl;

  m_intake.move(0);
  pros::delay(10);

  m_puncher.move(-127);
  pros::delay(1000);

  m_puncher.move(50);
  pros::delay(200);

  while(s_encoder.get_value()<35.5-(desianglemedium))
  {
    m_puncher.move(500);
    pros::delay(10);
  }
  m_puncher.move(0);
  pros::delay(100);



  std::cout << "==================code has reached second puncher aim==============================================" << master << std::endl;

  while(s_light.get_value_calibrated()>-50)
  {
    m_intake.move(127);
    pros::delay(10);
  }
  std::cout << "==================code has reached second ball intook==============================================" << master << std::endl;

  m_intake.move(-127);
  pros::delay(200);

  m_intake.move(0);
  pros::delay(10);

  m_puncher.move(-127);
  pros::delay(1000);

  m_puncher.move(0);
  pros::delay(10);

  std::cout << "==================code has reached stop==============================================" << master << std::endl;

}


void driverControlTask()
{

  if (HIDMain.get_digital(DIGITAL_R1))
  {
    m_puncher.move(-127);
  }

  else if (HIDMain.get_digital(DIGITAL_R2))
  {
    m_puncher.move(50);
  }

  else
  {
    m_intake.move(0);
    m_puncher.move(0);
  }

  if(HIDMain.get_digital(DIGITAL_Y))
  {
  //  ballshoot();
  }

}

void intakeTask()
{
  if (HIDMain.get_digital(DIGITAL_R1))                            //intake
  {
    if ((intakeSwitch = false))
    {
      m_intake.move(127);
      pros::delay(75);
    }

    if (s_intakeLight.get_value_calibrated() < -4)
    {
      m_intake.move(0);
      intakeSwitch = true;
    }
  }

  if (HIDMain.get_digital(DIGITAL_R2))
  {
    m_intake.move(-127);
  }

  else
  {
    intakeSwitch = false;
  }

}

double calcFlagDistance()
{
  if (s_ultrasonic1.get_value() < 5)
  {
    return s_ultrasonic2.get_value();
  }

  if (s_ultrasonic2.get_value() < 5)
  {
    return s_ultrasonic1.get_value();
  }
  else
  {
    return (s_ultrasonic1.get_value() + s_ultrasonic2.get_value()) /2;
  }
}
