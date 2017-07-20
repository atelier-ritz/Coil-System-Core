#ifndef COILFIELDCONTROL
#define COILFIELDCONTROL

#include "constantValue.h"
#include "s826_subroutine.h"
#include "vision.h"
# include "math_subroutine.h"

int coilCurrentClear(void);
int set_coil_current_to (int index, float d);
float get_coil_current(int index);
void set_field_xyz_2 (float bx, float by, float bz, float dbx, float dby, float dbz);
void resetCoils(void);

#endif
