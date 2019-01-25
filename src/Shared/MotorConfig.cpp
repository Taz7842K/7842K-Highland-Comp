#include "main.h"
#include "MainConfig.h"

const int e_frontLeft(17);
const int e_rearLeft(1);
const int e_frontRight(-13);
const int e_rearRight(-18);

pros::Motor m_frontLeft(abs(e_frontLeft), e_frontLeft<0);
pros::Motor m_frontRight(abs(e_frontRight), e_frontRight<0);
pros::Motor m_rearRight(abs(e_rearRight), e_rearRight<0);
pros::Motor m_rearLeft(abs(e_rearLeft), e_rearLeft<0);

pros::Motor m_puncher(14);
pros::Motor m_puncherAim(15);

pros::Motor m_intake(20);

pros::Motor lift(9);

pros::ADIUltrasonic s_ultrasonic1 ('A', 'B');
pros::ADIUltrasonic s_ultrasonic2 ('G', 'H');

pros::ADIPotentiometer s_autoSelect('C');

pros::ADILineSensor s_light ('F');

pros::ADILineSensor s_intakeLight ('E');

double movDel = 125;

double movMaxVel = 160;

double enc_puncher;


okapi::ChassisControllerIntegrated skidBase = ChassisControllerFactory::create(
  {e_frontLeft,e_rearLeft} ,{e_frontRight,e_rearRight},

  AbstractMotor::gearset::green,
  {4_in, 11.75_in});
