# Coil-System-Core

## Introduction

"Coil-System-Core" is a program to drive the 6-input coil system that is mainly written in C.  
With 2 more amplifiers added to the system, we are going to integrate different variations of the code and provide a stable, organized version for everyone to start with.

## How to compile

Open terminal in Linux and execute "make" in the target directory. The files included in "MakeFile" will be compiled. An executable file "tutorial" will be generated.

## Roadmap

Compare the codes that are written by all members, fix the bugs, and integrate them.

Reorganize the structure of the source code and make it easier to add new functions.

Unified naming convention for files.

Update dependent packages. (OpenCV etc?)

## List of files

826api.h: Include file for applications for Sensoray's model 826 board

AccelStepper.h: Arduino AccelStepper library. It provides an object-oriented interface for 2, 3 or 4 pin stepper motors. It is modified to control the amplifier driver.

AutoFabrication.h: [Zhe] Provides basic methods for magnatic field manipulation.

callbacks.h: Trigger functions with GUI.

coilFieldControl.h: Relate magnetic fields with the signal from s826 I/O. Calibration of the magnetic field is done here.

constantValue.h: Store constant values.

FWcamera.h: [c++] A class that handles cameras.

math_subroutine.h: Mathematical functions.

s826_subroutine.h: s826 I/O control.

twistField.h: [Omid] Generates a periodically rotating field.

vision.h: Process of vision and displaying videos on the GUI.
