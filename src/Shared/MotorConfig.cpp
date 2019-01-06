#include "main.h"
#include "MainConfig.h"

const int e_frontLeft(-17);
const int e_rearLeft(-19);
const int e_frontRight(12);
const int e_rearRight(18);

pros::Motor m_frontLeft(abs(e_frontLeft), e_frontLeft<0);
pros::Motor m_frontRight(abs(e_frontRight), e_frontRight<0);
pros::Motor m_rearRight(abs(e_rearRight), e_rearRight<0);
pros::Motor m_rearLeft(abs(e_rearLeft), e_rearLeft<0);

pros::Motor m_puncher(14);
pros::Motor m_intake(20);

pros::ADIUltrasonic s_ultrasonic (1, 2);
pros::ADIPotentiometer s_puncherPot(5);
pros::ADIEncoder s_encoder (3,4);
