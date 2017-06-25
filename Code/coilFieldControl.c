////////////////////////////////////////////////////////////////////////////////////////
// File      : coilFieldControl.c
// Function  : control magnetic fields using s826
// Edited by :
////////////////////////////////////////////////////////////////////////////////////////
#include "coilFieldControl.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static float coil_current_voltage[3] = {0,0,0};  //static float coil_current_x = 0, coil_current_y = 0, coil_current_z = 0;

int coilCurrentClear(void)
{
    coil_current_voltage[0] = 0;
    coil_current_voltage[1] = 0;
    coil_current_voltage[2] = 0;
    //update_coil_current();
    uint aoRange = 2;   // 2: -5 ~ +5 V.
    s826_aoPin( 0 , aoRange, 0);
    s826_aoPin( 1 , aoRange, 0);
    s826_aoPin( 2 , aoRange, 0);
}

int set_coil_current_to (int index, float d)
{
    coil_current_voltage[index] = d;
    switch (index)
    {
        case 0:
            s826_aoPin(0, 2, d/5.003);    // coil 1.0    x-left
            s826_aoPin(3, 2, d/4.879);    // coil 1.1    x-right
            break;
        case 1:
            s826_aoPin(1, 2, d/5.024);    // coil 2.0     y-left
            s826_aoPin(5, 2, d/4.433);    //  coil 3      y-right
            break;
        case 2:
            s826_aoPin(4, 2, d/5.143);    // coil 2.1     z-serial
            break;
    }
}

void set_field_xyz_2 (float bx, float by, float bz, float dbx, float dby, float dbz) {
    s826_aoPin(3, 2, bx*0.18754719386756); //x-right
    s826_aoPin(0, 2, bx*0.18754719386756); //x-left
    s826_aoPin(1, 2, by*-0.19230420653328); //y-left
    s826_aoPin(5, 2, by*-0.19230420653328); //y-right
    s826_aoPin(4, 2, bz*-0.191929507962791); //z-serial
}

void resetCoils(void) {
    set_field_xyz_2(0.0,0.0,0.0,0.0,0.0,0.0);
}

/* Get current coil current control voltage value */
float get_coil_current(int index){
    float returnValue = 0;
    if ( (index > 2) || (index < 0) )
        printf("Error in get_coil_current.\n");
    else
        returnValue = coil_current_voltage[index];
    return returnValue;
}
