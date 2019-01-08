#include "main.h"

//extern std::shared_ptr<AbstractMotor> frontRight;

extern pros::Controller HIDMain;

extern void baseControlTask(void*);
extern void driverControlTask(void*);
extern void autoSelectTask(void*);
extern void puncherTasks(void*);

extern const int puncher;

extern okapi::ChassisControllerPID mecBase;

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

extern pros::ADIPotentiometer s_puncherPot;
extern pros::ADIEncoder s_encoder;
extern pros::ADILineSensor s_light;

extern double distanceFromFlag1;
extern double distanceFromFlag2;
extern double distanceFromFlagCalc;
