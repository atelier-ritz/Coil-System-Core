////////////////////////////////////////////////////////////////////////////////////////
// File      : GeneralControl.h
// Function  : Tab: General Control
// Edited by : Tianqi
////////////////////////////////////////////////////////////////////////////////////////
#include <pthread.h>
#include <gtk/gtk.h>
#include "constantValue.h"
#include "s826_subroutine.h"

#include "coilFieldControl.h"
#include <stdio.h>
#include <math.h>

extern float factor_x, factor_y, factor_z;
extern float field_x, field_y, field_z, field_mag, field_angle;

void set_field_xyz (int, float);
void set_field_mode_xyz (float, float, float);
void set_field_mode_angle (float, float, float);
