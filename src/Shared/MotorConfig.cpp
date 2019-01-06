#include "main.h"
#include "MainConfig.h"

extern const int e_frontLeft(1);
extern const int e_frontRight(2);
extern const int e_rearRight(3);
extern const int e_rearLeft(4);

pros::Motor m_frontLeft(e_frontLeft, e_frontLeft<0);
pros::Motor m_frontRight(e_frontRight, e_frontRight<0);
pros::Motor m_rearRight(e_rearRight, e_rearRight<0);
pros::Motor m_rearLeft(e_rearLeft, e_rearLeft<0);

pros::Motor m_puncher(4);
pros::Motor m_Intake(5);

pros::ADIUltrasonic s_ultrasonic(1);
pros::ADIPotentiometer s_puncherPot(2);
pros::ADIEncoder s_encoder(9);
pros::ADILineSensor s_light(4);
