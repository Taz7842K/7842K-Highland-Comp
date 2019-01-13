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

void baseControlFunction()
{

  double joystickDeadband = 0;

    std::cout<<"basecontroltask is running"<<std::endl;

    double Joystickch2_forward = HIDMain.getAnalog(ControllerAnalog::rightY) * -1.0;
    double Joystickch4_turn = (HIDMain.getAnalog(ControllerAnalog::leftX)/2);

    skidBase.arcade(Joystickch2_forward,Joystickch4_turn, joystickDeadband);
}
