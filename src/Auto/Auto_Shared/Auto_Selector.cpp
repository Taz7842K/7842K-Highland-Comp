#include "main.h"
#include "Auto/Shared_Auto/Auto_Selector.h"

pros::ADIPotentiometer pot_auto_select('A');

int e_auto_select = pot_auto_select.get_value();

 std::string f_gui_auto_select_task(std::string gui_auto_select)
{

  while(true)
  {

      if (e_auto_select < 4095)
    {
      return "0_Skills";
    }

    else if (e_auto_select < 4095)
    {
      return "1_Blue_front";
    }

    else if (e_auto_select < 4095)
    {
      return "2_Blue_Rear";
    }

    else if (e_auto_select < 4095)
    {
      return "3_Red_Front";
    }

    else if (e_auto_select < 4095)
    {
      return "4_Red_Rear";
    }

    else
    {
      return 0;
    }
  }
}

void f_auto_run(void*)
{

   if (e_auto_select < 4095)
   {
     auto_0();

   }

   else if (e_auto_select < 4095)
   {
     auto_1();
   }

   else if (e_auto_select < 4095)
   {
     auto_2();
   }

   else if (e_auto_select < 4095)
   {
     auto_3();
   }

   else if (e_auto_select < 4095)
   {
     auto_4();
   }

   else if (e_auto_select < 4095)
   {
     auto_5();
   }
}
