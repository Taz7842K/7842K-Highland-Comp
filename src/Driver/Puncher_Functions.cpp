#include "main.h"
#include "Driver/Puncher_States.h"
#include"MainConfig.h"

double  pGain = 0.1;
double  iGain = 0.0;
double  dGain = 0.0;

double puncherAngleRange = 39; //PLACEHOLDER!!

 okapi::AsyncPosPIDController puncherPIDController = AsyncControllerFactory::posPID(m_puncher,s_encoder,0.1,0,0);

void movetoHighFlagFunction()
{

  if(desianglehigh > puncherAngleRange)
  {
    // HIDMain.rumble(. .);
  }
  else if (desianglehigh < puncherAngleRange)
  {
    if(desianglehigh < s_encoder.get())
    {
      while(desianglehigh < 10)
      {
        m_puncher.moveVelocity(75);
      }
    }
    else if(desianglehigh > s_encoder.get())
    {
      puncherPIDController.setTarget(puncherAngleRange - (desianglehigh - s_encoder.get()));
      puncherPIDController.waitUntilSettled();
    }
  }
}


void movetoMidFlagFunction()
{
  if(desianglemedium > puncherAngleRange)
  {
    // HIDMain.rumble('. .');
  }
  else if (desianglemedium < puncherAngleRange)
  {
    if(desianglehigh < s_encoder.get())
    {
      while(desianglemedium < 10)
      {
        m_puncher.moveVelocity(75);
      }
    }
    else if(desianglemedium > s_encoder.get())
    {
      puncherPIDController.setTarget(puncherAngleRange - (desianglemedium - s_encoder.get()));
      puncherPIDController.waitUntilSettled();
    }
  }
}

void shootFlagFunction()
{
  while(s_light.get_value_calibrated()>-100)
  {
    m_intake.move(127);
    pros::delay(10);
  }

  m_intake.moveRelative(900,200);

  while(s_light.get_value_calibrated()<-100)
  {
    m_puncher.move(-127);
    pros::delay(10);
  }

}

double calc_FlagDistance(double distanceFromFlag1, double distanceFromFlag2)
{
  if (distanceFromFlag1 < 5)
  {
    return distanceFromFlag2;
  }

  else if (distanceFromFlag2 < 5)
  {
    return distanceFromFlag1;
  }

  else
  {
    return distanceFromFlag1 + distanceFromFlag2 /2;
  }
}
