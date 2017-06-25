////////////////////////////////////////////////////////////////////////////////////////
// File      : math_subroutine.c
// Function  : Mathematical functions
// Edited by :
////////////////////////////////////////////////////////////////////////////////////////
# include "math_subroutine.h"

/// Absolute Value for Float Type
float abs_f (float value) {
  if (value < 0)
    return -value;
  else
    return value;
}

/// Change Angle to (-PI, PI]; Input: a_angle_radian: angle requires adjustment. Unit: radian
float adjust_angle_range (float a_angle_radian)
{
    float l_angle_radian = a_angle_radian;
    l_angle_radian = fmodf(l_angle_radian, 2*M_PI);   // (-2*PI, 2*PI)
    if (l_angle_radian > M_PI)
        l_angle_radian = l_angle_radian - 2*M_PI;     // (-2*PI,   PI]
    else if (l_angle_radian <= (-M_PI) )
        l_angle_radian = l_angle_radian + 2*M_PI;     // (  -PI,   PI]
    return l_angle_radian;
}

float get_abs_angle_diff ( float angle_1, float angle_2 )
{
	float diff = adjust_angle_range (angle_1 - angle_2);
	diff = abs_f (diff);
	return diff;
}

// Get dis from a point to a line segment
double calc_dis_from_point_to_line ( int point[2], int line[4] )
{
	int x0 = point[ 0 ];
	int y0 = point[ 1 ];
	int	x1 = line[ 0 ];
	int	y1 = line[ 1 ];
	int x2 = line[ 2 ];
	int y2 = line[ 3 ];
	double dis = abs_f( ( y2-y1 ) * x0 - ( x2-x1 ) * y0 + x2*y1 - x1*y2 ) / sqrt( pow( (y2-y1), 2) + pow( (x2-x1), 2) );
	return dis;
}
