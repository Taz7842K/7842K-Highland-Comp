#include "main.h"

//extern std::shared_ptr<AbstractMotor> frontRight;

extern okapi::Controller HIDMain;

extern void baseControlTask(void*);
extern void driverControlTask(void*);
extern void autoSelectTask(void*);
extern void puncherTasks(void*);

extern void auto_0();
extern void auto_1();
extern void auto_2();
extern void auto_3();
extern void auto_4();
extern void auto_5();

extern okapi::ChassisControllerIntegrated skidBase;

extern const int puncher;

extern const int e_frontLeft;
extern const int e_frontRight;
extern const int e_rearRight;
extern const int e_rearLeft;

extern okapi::Motor m_puncher;
extern okapi::Motor m_intake;

extern pros::ADIUltrasonic s_ultrasonic1;
extern pros::ADIUltrasonic s_ultrasonic2;

extern pros::ADIPotentiometer s_puncherPot;
extern okapi::ADIEncoder s_encoder;
extern pros::ADILineSensor s_light;

extern double distanceFromFlag1;
extern double distanceFromFlag2;
extern double distanceFromFlagCalc;
