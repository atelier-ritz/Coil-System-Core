////////////////////////////////////////////////////////////////////////////////////////
// File      : vision.h
// Function  : Camera-related subroutines
// Edited by : Jiachen, Zhe
////////////////////////////////////////////////////////////////////////////////////////
#ifndef RCVIS
#define RCVIS

#include <gtk/gtk.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
//#include <math.h>
//#include <vector>

#include <sys/time.h>
#include "FWcamera.h"
#include "DataGlobalVariables.h"

using namespace cv;

extern GtkImage *videoWindow, *videoWindow2;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Edited by Jiachen
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern Point centerP;

Mat getImage(void);                 // Get the image to display on the vidWin1
Mat getImage2(void);                // Get the image to display on the vidWin2

void initVision();
void stopVision(void);
void* FPSprint(void*);
void* FPSprint_xz(void*);
void* visionThread(void*);
void* visionThread_xz(void*);

GdkPixbuf *convertOpenCv2Gtk(IplImage *image);
void set_edgemap(int);
void set_binary(int);
void setGain_vision(int);
void setShutter_vision(int);
void setDilate_vision(int);
void setvisionParam1_vision(int);
void setvisionParam2_vision(int);
void setdetect_vision(int);
void setcannyLow_vision(int);
void setcannyHigh_vision(int);

// X-Z Camera
void setTopCam_vision(int d);
void set_edgemap_xz(int);
void set_binary_xz(int);
void setGain_xz_vision(int);
void setShutter_xz_vision(int);
void setDilate_xz_vision(int);
void setvisionParam1_xz_vision(int);
void setvisionParam2_xz_vision(int);
void setdetect_xz_vision(int);
void settopcam_xz_vision(int);
void setcannyLow_xz_vision(int);
void setcannyHigh_xz_vision(int);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setMouse(int whichScreen, int whichMouse, int mouseClick[2] ); //click in pixels

static void draw_xy_magnetic_field (Mat,float,float);
static void draw_xz_magnetic_field (Mat,float,float);
static void draw_3d_magnetic_field (Mat,float,float);


#endif
