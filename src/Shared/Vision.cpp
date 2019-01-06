#include "main.h"

typedef struct __attribute__((__packed__)) vision_signature {
  uint8_t id;
  uint8_t _pad[3];
  float range;
  int32_t u_min;
  int32_t u_max;
  int32_t u_mean;
  int32_t v_min;
  int32_t v_max;
  int32_t v_mean;
  uint32_t rgb;
  uint32_t type;
} flag_sig;

struct flag_object{
  // Object signature
  uint16_t signature;
  // Object type, e.g. normal, color code, or line detection
  //vision_object_type_e_t type;
  // left boundary coordinate of the object
  uint16_t left_coord;
  // top boundary coordinate of the object
  uint16_t top_coord;
  // width of the object
  uint16_t width;
  // height of the object
  uint16_t height;
  // Angle of a color code object in 0.1 degree units (e.g. 10 -> 1 degree, 155 -> 15.5 degrees)
  uint16_t angle;

  // coordinates of the middle of the object (computed from the values above)
  int x_middle_coord;
  uint16_t y_middle_coord;
};

flag_object top_flag;

top_flag.x_middle_coord = 2;

void center_puncher(void)
{
  if (flag_object. < VISION_FOV_WIDTH/2)
  {
    
  }
}


pros::Vision main_Vision(2);

 main_Vision.clear_led();
