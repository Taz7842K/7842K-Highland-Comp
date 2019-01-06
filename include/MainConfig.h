#include "main.h"



extern pros::Controller HIDMain;

extern void baseControlTask(void*);
extern void driverControlTask(void*);


extern const int puncher;

extern const int e_frontLeft;
extern const int e_frontRight;
extern const int e_rearRight;
extern const int e_rearLeft;

extern pros::Motor m_frontLeft;
extern pros::Motor m_frontRight;
extern pros::Motor m_rearRight;
extern pros::Motor m_rearLeft;

extern pros::Motor m_puncher;
extern pros::Motor m_intake;

extern pros::ADIUltrasonic s_ultrasonic;
extern pros::ADIPotentiometer s_puncherPot;
extern pros::ADIEncoder s_encoder;
