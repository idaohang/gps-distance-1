#include <math.h>
#include "geofencelib.h"
/* Conversion function */
static double deg2rad(double deg)
{
    return ((deg*PI)/180);
}

/* Distance calculation using Haversine Formula.*/
double getDistanceFromLatLonInMeter(double lat1, double lon1, double lat2, double lon2)
{
    double dLat = deg2rad(lat1 -lat2);
    double dLon = deg2rad(lon1 - lon2);

    /* Use Haversine Formula*/
    double a = sin(dLat/2) * sin(dLat/2) +
        cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
        sin(dLon/2) * sin(dLon/2);
    double c =2 * atan2(sqrt(a), sqrt(1-a));
    double d = EARTH_RADIUS * c;

    return d;
}

/* Indicate if a given position (position_lat, position_lon) is */
/* inside a circular fence                                      */
BOOL isPointInsideFence(double fence_radius, double center_lat, double center_lon, double position_lat, double position_lon )
{

    return ( getDistanceFromLatLonInMeter(center_lat, center_lon, position_lat, position_lon) < fence_radius );
}

/* Indicates if a given position is inside a known polygon              */
/* Arg:                                                                 */
/* - int number_of_intersections:                                       */
/*   how many times a ray starting from and going any fixed direction,  */
/*   intersects the edges of the polygon                                */
BOOL isPointInsidePolygon(int number_of_intersections)
{
    /* Ray Castling Algorithm */
    if(number_of_intersections % 2 == 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
