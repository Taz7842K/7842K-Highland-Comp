#include "main.h"

extern pros::Controller HIDMain;

void baseControlTask();
void driverControlTask();
double calcFlagDistance();
void calcAngle();
void intakeTask();

void movetoHighFlagFunction();
void movetoMidFlagfunction();
void shootFlagFunction();

extern okapi::ChassisControllerIntegrated skidBase;

extern const int puncher;

extern double enc_puncher;

extern const int e_frontLeft;
extern const int e_frontRight;
extern const int e_rearRight;
extern const int e_rearLeft;

extern pros::Motor m_frontLeft;
extern pros::Motor m_frontRight;
extern pros::Motor m_rearRight;
extern pros::Motor m_rearLeft;

extern pros::Motor m_puncher;
extern pros::Motor m_puncherAim;

extern pros::Motor m_intake;

extern pros::ADIUltrasonic s_ultrasonic1;
extern pros::ADIUltrasonic s_ultrasonic2;

extern pros::ADIPotentiometer s_puncherPot;
extern pros::ADIEncoder s_encoder;

extern pros::ADILineSensor s_light;
extern pros::ADILineSensor s_intakeLight;

void auto_0();
void auto_1();
void auto_2();
void auto_3();
void auto_4();
void auto_5();

extern double desianglehigh;
extern double desianglemedium;
extern double distancefromflag;
