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

extern puncher_states stateofPuncher = doNothing;

extern ballshoot;

extern void movetoHighFlagFunction();
extern void shootHighFlagFunction();
extern void movetoMidFlagFunction();
extern void shootMidFlagFunction();
