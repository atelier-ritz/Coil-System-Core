////////////////////////////////////////////////////////////////////////////////////////
// File      : PageGeneralControl.h
// Function  : Tab: General Control
// Edited by : Tianqi
////////////////////////////////////////////////////////////////////////////////////////
#include <pthread.h>
#include <gtk/gtk.h>
#include "ConstantValue.h"
#include "s826_subroutine.h"
#include "coilFieldControl.h"
#include <stdio.h>
#include <math.h>

void set_field_xyz (int, float);
void set_field_mode_xyz (float, float, float);
void set_field_mode_angle (float, float, float);
