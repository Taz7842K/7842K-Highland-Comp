#include "main.h"
#include "MainConfig.h"

okapi::Controller HIDMain(ControllerId::master);

// void setBasePower(int xPower, int yPower, int zPower)
// {
//   m_frontLeft.move(yPower-xPower-zPower);
// 	m_rearRight.move(yPower+xPower-zPower);
// 	m_frontLeft.move(yPower+xPower+zPower);
//   m_rearLeft.move(yPower-xPower+zPower);
// }

void baseControlTask(void*)
{

  std::cout<<"basedcontroltask is running"<<std::endl;

  double joystickDeadband = 10;

  while(true)
  {
    double Joystickch2_forward = HIDMain.getAnalog(ControllerAnalog::leftX) * 0.75;
    double Joystickch4_turn = HIDMain.getAnalog(ControllerAnalog::rightY);

    skidBase.arcade(Joystickch2_forward,Joystickch4_turn, joystickDeadband);
  }
}
