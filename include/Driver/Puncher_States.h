#include "main.h"

extern bool puncherSwitch;

enum puncher_states
{
  doNothing,
  movetoMidFlag,
  shootHighFlag,
  movetoHighFlag,
  shootMidFlag
};

extern puncher_states stateofPuncher;

extern void puncherTasks(void*);

extern void movetoHighFlagFunction();
extern void shootHighFlagFunction();
extern void movetoMidFlagFunction();
extern void shootMidFlagFunction();


extern double distanceFromFlag1;
extern double distanceFromFlag2;
extern double distanceFromFlagCalc;
extern double distanceFromFlag;
extern double desianglehigh;
extern double desianglemedium;
