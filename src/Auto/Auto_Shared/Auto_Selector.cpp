#include "main.h"

pros::ADIPotentiometer pot_auto_select('A');

extern void f_auto_select()
{
  if (pot_auto_select < 100)
  {}
}
