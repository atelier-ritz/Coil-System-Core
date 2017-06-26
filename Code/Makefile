CXX = g++
#FLAGS = -ggdb -Wall
FLAGS = -ggdb

#main: main.cc
#	${CXX} ${FLAGS} -o main main.cc

#clean:
#	rm -f main

tutorial: main.c callbacks.c vision.c s826_subroutine.c FWcamera.cpp coilFieldControl.c twistField.c  math_subroutine.c

${CXX} ${FLAGS} -std=c++0x `pkg-config --cflags gtk+-2.0` -o tutorial main.c callbacks.c vision.c s826_subroutine.c math_subroutine.c coilFieldControl.c  twistField.c  AccelStepper.cpp FWcamera.cpp -export-dynamic `pkg-config --libs gtk+-2.0` -lm `pkg-config --cflags --libs opencv --libs` -l826_64  -lraw1394 -ldc1394
