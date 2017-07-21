////////////////////////////////////////////////////////////////////////////////////////
// File      : PageGeneralControl.c
// Function  : Tab: General Control
// Edited by : Tianqi
////////////////////////////////////////////////////////////////////////////////////////
#include "PageGeneralControl.h"

//field control
bool coil_3d = true, coil_2d_xz = false;
float field_mag_fab = 0.0;
float field_x = 0.0, field_y = 0.0, field_z = 0.0, field_mag = 0.0, field_angle = 0.0;
float field_angle_m = 0.0; // field_angle in magnet coordinate
float factor_x = 5.0964, factor_y = 4.999, factor_z = 5.1677;

void set_factor (int index)
{
	switch (index) // 1:3D coil system; 0:2D coil system
	{
		case 0: coil_3d = true;
                factor_x = 5.0964; factor_y = 4.999; factor_z = 5.1677;
                printf("3D coil system selected\n");
				break;
		case 1: coil_3d = false; coil_2d_xz = true;
                factor_x = 5.2264; factor_z = 5.8538;
                printf("2D X-Z selected\n");
				break;
        case 2: coil_3d = false; coil_2d_xz = false;
                factor_x = 5.2264; factor_y = 5.8538;
                printf("2D X-Y selected\n");
				break;
	}
}

void set_field_xyz (int index, float d) // indices 123 -> xyz. for 3d, controller 012 -> xyz; for 2d, controller 0,1 -> x,(y or z)
{
    switch (index) // 0:x  1:y  2:z
    {
        case 0: field_x = d; set_coil_current_to (0, d);
                break;

        case 1: if ( !coil_3d & coil_2d_xz )
                    break;
                else
                {
                    field_y = d;
                    set_coil_current_to (1, d);
                    break;
                }

        case 2: if ( !coil_3d & !coil_2d_xz )
                    break;
                else
                {
                    field_z = d;
                    if (coil_3d)
                        set_coil_current_to (2, d);
                    else
                        set_coil_current_to (1, d);
                    break;
                }
    }
	field_mag = sqrt( pow(field_x,2) + pow(field_y,2) + pow(field_z,2) ) ;
	field_angle = atan2(field_z, field_x) * 180.0/M_PI; // atan2() => (-pi, pi]
}

void set_field_mode_xyz(float x,float y,float z) {
  set_field_xyz (0, x);
  set_field_xyz (1, y);
  set_field_xyz (2, z);
}

void set_field_mode_angle(float mag,float xy,float xz) {
  float z = mag * sind(xz);
  float y = mag * cosd(xz) * sind(xy);
  float x = mag * cosd(xz) * cosd(xy);
  set_field_xyz (0, x);
  set_field_xyz (1, y);
  set_field_xyz (2, z);
}
