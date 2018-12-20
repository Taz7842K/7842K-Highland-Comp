#include "main.h"
#include "Auto/Shared_Auto/Auto_Selector.h"


pros::ADIPotentiometer pot_auto_select('A');

int e_auto_select = pot_auto_select.get_value();

int gui_auto_select = -1;

extern void f_auto_select()
{
  if (e_auto_select < 4095)
  {
    gui_auto_select = 0;
    auto_0();
  }

  else if (e_auto_select < 4095)
  {
    gui_auto_select = 1;
    auto_1();
  }

  else if (e_auto_select < 4095)
  {
    gui_auto_select = 2;
    auto_2();
  }

  else if (e_auto_select < 4095)
  {
    gui_auto_select = 3;
    auto_3();
  }

  else if (e_auto_select < 4095)
  {
    gui_auto_select = 4;
    auto_4();
  }

  else if (e_auto_select < 4095)
  {
    gui_auto_select = 5;
    auto_5();
  }
}
