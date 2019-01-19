#include "main.h"
#include "MainConfig.h"

int master;

double puncherAngleRange = 39;

bool intakeSwitch = false;

const double _pi = 3.141592653589793238462643383279502886;

double distancefromflag;
double desianglehigh;
double desianglemedium;

void calcAngle()
{
  std::cout << "==================code has reached start==============================================" << master << std::endl;

  distancefromflag = (((calcFlagDistance()/2.54)/10)-10);

  desianglehigh = (atanf(38.8/distancefromflag)*(180/_pi));
  desianglemedium = (atanf(24.4/distancefromflag)*(180/_pi));

  std::cout << "distance:" << distancefromflag << std::endl;
  std::cout << "medium angle:" << desianglemedium << std::endl;
  std::cout << "high angle:" << desianglehigh << std::endl;
  std::cout << "agnle sensor value:" << enc_puncher << std::endl;

  enc_puncher = ((m_puncherAim.get_position())*900/360);
}



void intakeTask()
{
  if (HIDMain.get_digital(DIGITAL_L1))                            //intake
  {
      m_intake.move(127);
  }

  else if (HIDMain.get_digital(DIGITAL_L2))
  {
    m_intake.move(-127);
  }

  else
  {
    m_intake.move(0);
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
