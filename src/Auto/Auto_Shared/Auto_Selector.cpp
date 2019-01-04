#include "main.h"

#include "Auto/Shared_Auto/Auto_Selector.h"

pros::ADIPotentiometer pot_auto_select('A');

void autoSelectTask(void*)
{

  while(true)
  {

    int e_auto_select = pot_auto_select.get_value();

   if (e_auto_select < 4095)
   {
     int_auto_select = 0;
     std::string gui_auto_select = "Skills";
   }

   else if (e_auto_select < 4095)
   {
     int_auto_select = 1;
     std::string gui_auto_select = "Blue Front";
   }

   else if (e_auto_select < 4095)
   {
     int_auto_select = 2;
     std::string gui_auto_select = "Blue Rear";
   }

   else if (e_auto_select < 4095)
   {
     int_auto_select = 4;
     std::string gui_auto_select = "Red Front";
   }

   else if (e_auto_select < 4095)
   {
     int_auto_select = 5;
     std::string gui_auto_select = "Red Rear";
   }
 }
}
