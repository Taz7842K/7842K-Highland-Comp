#include "main.h"
#include "MainConfig.h"

const double PI = 3.141592653589793238462643383279502886;

void ballshoot()
{
  s_encoder.reset();


  double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));
  double desianglehigh = (atanf(distancefromflag/38.3)*(180/PI));
  double desianglemedium = (atanf(distancefromflag/24.4)*(180/PI));

  std::cout << "distance:" << distancefromflag << std::endl;
  std::cout << "high angle:" << desianglehigh << std::endl;



  while(s_encoder.get_value()<40.5-(desianglemedium))
  {
    m_puncher.move(50);
    pros::delay(10);
  }
  m_puncher.move(0);
  pros::delay(10);
  m_intake.move(127);
  pros::delay(1500);
  m_intake.move(0);
  m_puncher.move(-127);
  pros::delay(1000);
  m_puncher.move(0);
  pros::delay(10);

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

    if(HIDMain.get_digital(DIGITAL_Y))
    {
      ballshoot();
    }

    pros::delay(20);

  }
}
