#include "main.h"
#include "MainConfig.h"


 int master;
const double PI = 3.141592653589793238462643383279502886;


double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10)-12);
double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));



void driverControlTask(void*)
{

  while(true)
  {

    // std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;
    // std::cout << "Light Sensor:" << s_light.get_value_calibrated() << std::endl;
    s_encoder.reset();

    if (HIDMain.get_digital(DIGITAL_R1))
    {
      m_puncher.move(-127);
    }

    else if (HIDMain.get_digital(DIGITAL_R2))
    {
      m_puncher.move(38);
    }
    else
    {
      m_puncher.move(0);
    }
//cap remover
    if (HIDMain.get_digital(DIGITAL_R1))
    {
      lift.move(-127);
    }

    else if (HIDMain.get_digital(DIGITAL_R2))
    {
      lift.move(127);
    }
    else
    {
      lift.move(0);
    }


    if (HIDMain.get_digital(DIGITAL_L1))
    {
      master = 2;
      m_intake.move(-127);
    }

    else if (HIDMain.get_digital(DIGITAL_L2))
    {
      master = 2;
      m_intake.move(127);
    }
    else
    {
      m_intake.move(0);
    }


    while(HIDMain.get_digital(DIGITAL_X))
    {

      std::cout << "==================code has reached start==============================================" << master << std::endl;

             double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));

             if (distancefromflag< 20)
             {

               distancefromflag = 40;

             }

             double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
             double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));

             std::cout << "distance:" << distancefromflag << std::endl;
             std::cout << "medium angle:" << desianglemedium << std::endl;
             std::cout << "high angle:" << desianglehigh << std::endl;
             std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


             m_aim.move_relative((((900/360)*(35.5-desianglehigh))*-5), 100);
             m_puncher.move(0);
             pros::delay(600);

             std::cout << "distance:" << distancefromflag << std::endl;
             std::cout << "medium angle:" << desianglemedium << std::endl;
             std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


             std::cout << "==================code has reached second puncher aim==============================================" << master << std::endl;

           while(s_light.get_value_calibrated()>-50)
           {
             m_intake.move(127);
             pros::delay(10);
           }
           std::cout << "==================code has reached second ball intook==============================================" << master << std::endl;

           m_intake.move(-127);
           pros::delay(200);

           m_intake.move(0);
           pros::delay(10);

           m_puncher.move(-127);
           pros::delay(1000);

           m_puncher.move(0);
           pros::delay(10);

           m_aim.move_relative((((900/360)*(35.5-desianglehigh))*4.7), 100);
           m_puncher.move(0);
           pros::delay(500);

             std::cout << "==================code has reached stop==============================================" << master << std::endl;


    }



    while(HIDMain.get_digital(DIGITAL_B))
    {
      std::cout << "==================code has reached start==============================================" << master << std::endl;

             double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));

             if (distancefromflag< 20)
             {

               distancefromflag = 40;

             }

             double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
             double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));

             std::cout << "distance:" << distancefromflag << std::endl;
             std::cout << "medium angle:" << desianglemedium << std::endl;
             std::cout << "high angle:" << desianglehigh << std::endl;
             std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


             m_aim.move_relative((((900/360)*(35.5-desianglemedium))*-5), 100);
             m_puncher.move(0);
             pros::delay(600);

             std::cout << "distance:" << distancefromflag << std::endl;
             std::cout << "medium angle:" << desianglemedium << std::endl;
             std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;

             std::cout << "==================code has reached second puncher aim==============================================" << master << std::endl;

           while(s_light.get_value_calibrated()>-50)
           {
             m_intake.move(127);
             pros::delay(10);
           }
           std::cout << "==================code has reached second ball intook==============================================" << master << std::endl;

           m_intake.move(-127);
           pros::delay(200);

           m_intake.move(0);
           pros::delay(10);

           m_puncher.move(-127);
           pros::delay(1000);

           m_puncher.move(0);
           pros::delay(10);

           m_aim.move_relative((((900/360)*(35.5-desianglemedium))*4.7), 100);
           m_puncher.move(0);
           pros::delay(500);

             std::cout << "==================code has reached stop==============================================" << master << std::endl;

    }

    while(HIDMain.get_digital(DIGITAL_Y))
    {


      double desianglehigh = (atanf(38.8/distancefromflag)*(180/PI));
      double desianglemedium = (atanf(24.4/distancefromflag)*(180/PI));


            std::cout << "==================code has reached start==============================================" << master << std::endl;

                   double distancefromflag = (((s_ultrasonic.get_value()/2.54)/10));

                   if (distancefromflag< 20)
                   {

                     distancefromflag = 40;

                   }


                   std::cout << "distance:" << distancefromflag << std::endl;
                   std::cout << "medium angle:" << desianglemedium << std::endl;
                   std::cout << "high angle:" << desianglehigh << std::endl;
                   std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


                   m_aim.move_relative((((900/360)*(35.5-desianglehigh))*-5), 100);
                   m_puncher.move(0);
                   pros::delay(600);

                   std::cout << "distance:" << distancefromflag << std::endl;
                   std::cout << "medium angle:" << desianglemedium << std::endl;
                   std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


                   std::cout << "==================code has reached second puncher aim==============================================" << master << std::endl;

                 while(s_light.get_value_calibrated()>-50)
                 {
                   m_intake.move(127);
                   pros::delay(10);
                 }
                 std::cout << "==================code has reached second ball intook==============================================" << master << std::endl;

                 m_intake.move(-127);
                 pros::delay(200);

                 m_intake.move(0);
                 pros::delay(10);

                 m_puncher.move(-127);
                 pros::delay(1000);

                 m_puncher.move(0);
                 pros::delay(10);

                 m_aim.move_relative((((900/360)*(35.5-desianglehigh))*4.7), 100);
                 m_puncher.move(0);
                 pros::delay(500);

//middle point


       std::cout << "distance:" << distancefromflag << std::endl;
       std::cout << "medium angle:" << desianglemedium << std::endl;
       std::cout << "high angle:" << desianglehigh << std::endl;
       std::cout << "agnle sensor value:" << s_encoder.get_value() << std::endl;


       m_aim.move_relative((((900/360)*(35.5-desianglemedium))*-5), 100);
       m_puncher.move(0);
       pros::delay(600);


       std::cout << "==================code has reached second puncher aim==============================================" << master << std::endl;

     while(s_light.get_value_calibrated()>-50)
     {
       m_intake.move(127);
       pros::delay(10);
     }
     std::cout << "==================code has reached second ball intook==============================================" << master << std::endl;

     m_intake.move(-127);
     pros::delay(200);

     m_intake.move(0);
     pros::delay(10);

     m_puncher.move(-127);
     pros::delay(1000);

     m_puncher.move(0);
     pros::delay(10);

     m_aim.move_relative((((900/360)*(35.5-desianglemedium))*4.7), 100);
     m_aim.move(0);
     pros::delay(500);

       std::cout << "==================code has reached stop==============================================" << master << std::endl;



    }

}

}
