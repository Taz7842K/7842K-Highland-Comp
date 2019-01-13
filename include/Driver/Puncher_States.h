#include "main.h"

extern void puncherTasks(void*);

extern void movetoHighFlagFunction();
extern void movetoMidFlagFunction();
extern void shootFlagFunction();

extern okapi::AsyncPosPIDController puncherPIDController;

extern double distanceFromFlag1;
extern double distanceFromFlag2;
extern double distanceFromFlagCalc;
extern double distanceFromFlag;
extern double desianglehigh;
extern double desianglemedium;
