////////////////////////////////////////////////////////////////////////////////////////
// File      : PageSwimmer.c
// Function  : Tab: swimmer
// Edited by : Tianqi
////////////////////////////////////////////////////////////////////////////////////////
#include "PageSwimmer.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static bool flag_field_on = false;
static float b_rot_mag = 0.0, b_rot_freq = 0.0;
static float b_str_mag = 0.0, b_str_angle = 0.0;
static float heading = 0.0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Thread
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void* swimmer_field_thread (void*threadid){
    printf("Swimmer thread started\n");

    struct timeval start;
    double bx, by, bz;
    double time_last, time_elapsed, time_out, time_out_sum, vx, vy, vz; //time in second
    double theta;

    gettimeofday(&start, NULL);

    double time_initial = (double) start.tv_sec + start.tv_usec*1e-6 ; // Initial time in seconds.

    while(flag_field_on){
        gettimeofday(&start, NULL);
        time_last = (double) start.tv_sec + start.tv_usec*1e-6 ;

		// vx = Bmag * ((cosd(theta_local)*cosd(beta_local))*(cosd(90-phi_local*0.5)*cosd(360.0*omega_local*time_elapsed)) - sind(theta_local)*(cosd(90-phi_local*0.5)*sind(360.0*omega_local*time_elapsed)) + cosd(theta_local)*sind(beta_local)*cosd(phi_local*0.5));
		// vy = Bmag * ((sind(theta_local)*cosd(beta_local))*(cosd(90-phi_local*0.5)*cosd(360.0*omega_local*time_elapsed)) + cosd(theta_local)*(cosd(90-phi_local*0.5)*sind(360.0*omega_local*time_elapsed)) + sind(theta_local)*sind(beta_local)*cosd(phi_local*0.5));
		// vz = Bmag * (-sind(beta_local)*(cosd(90-phi_local*0.5)*cosd(360.0*omega_local*time_elapsed)) + cosd(beta_local)*cosd(phi_local*0.5));
        //
        //
        theta = 360.0*b_rot_freq*time_elapsed;
        bx = b_rot_mag*sind(theta)*cosd(heading) + b_str_mag*cosd(heading + b_str_angle);
        by = b_rot_mag*sind(theta)*sind(heading) + b_str_mag*sind(heading + b_str_angle);
        bz = b_rot_mag*cosd(theta);

        set_field_mode_xyz(bx,by,bz);

        time_elapsed = time_last - time_initial -time_out;
        time_out_sum = time_out;

    }
    resetCoils();
    printf("Swimmer thread ended\n");
    return NULL;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Callbacks
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_swm_field (void){
    printf("@ the Beginning of swimmer thread.\n");
    flag_field_on = true;
    pthread_t swimmer_field;
    pthread_create(&swimmer_field, NULL, swimmer_field_thread, NULL);
}

void stop_swm_field(void){flag_field_on = false;}

void set_swm_rotate_mag(float d){b_rot_mag = d;}

void set_swm_rotate_freq(float d){b_rot_freq = d;}

void set_swm_steer_mag(float d){b_str_mag = d;}

void set_swm_steer_angle(float d){b_str_angle = d;}

void set_swm_heading(float d){heading = d;}
