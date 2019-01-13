#include "main.h"
#include "MainConfig.h"

const int e_frontLeft(-17);
const int e_rearLeft(-1);
const int e_frontRight(11);
const int e_rearRight(18);


// pros::Motor m_frontLeft(abs(e_frontLeft), e_frontLeft<0);
// pros::Motor m_frontRight(abs(e_frontRight), e_frontRight<0);
// pros::Motor m_rearRight(abs(e_rearRight), e_rearRight<0);
// pros::Motor m_rearLeft(abs(e_rearLeft), e_rearLeft<0);

okapi::Motor m_puncher(14);
okapi::Motor m_intake(20);

pros::ADIUltrasonic s_ultrasonic1('A', 'B');
pros::ADIUltrasonic s_ultrasonic2('G','H');

pros::ADIPotentiometer s_puncherPot('E');
okapi::ADIEncoder s_encoder = ADIEncoder('C','D',false);
pros::ADILineSensor s_light ('F');
