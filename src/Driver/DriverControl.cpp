#include "main.h"
#include "MainConfig.h"

const double PI = 3.141592653589793238462643383279502886;

void ballshoot()
{
  s_encoder.reset();


  double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));
  double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
  double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));

  std::cout << "distance:" << distancefromflag << std::endl;
  std::cout << "medium angle:" << desianglemedium << std::endl;



  while(s_encoder.get_value()<40.5-(desianglehigh))
  {
    m_puncher.move(50);
    pros::delay(10);
  }
  m_puncher.move(0);
  pros::delay(10);
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

  while(s_encoder.get_value()<37.5-(desianglemedium))
  {
    m_puncher.move(50);
    pros::delay(10);
  }
  m_puncher.move(0);
  pros::delay(10);
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


void driverControlTask(void*)
{

  while(true)
  {

    std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;
    std::cout << "Light Sensor:" << s_light.get_value_calibrated() << std::endl;

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




    if (HIDMain.get_digital(DIGITAL_L1))
    {
      m_intake.move(-127);
    }

    else if (HIDMain.get_digital(DIGITAL_L2))
    {
      m_intake.move(127);
    }
    else
    {
      m_intake.move(0);
    }



    if(HIDMain.get_digital(DIGITAL_Y))
    {
      ballshoot();
    }

    pros::delay(20);

  }
}
