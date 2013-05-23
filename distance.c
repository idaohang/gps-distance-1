#include <math.h>
#include <stdio.h>
#define EARTH_RADIUS 6371000
#define PI 3.14159265359

/* Conversion function */
double deg2rad(double deg)
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

int main (void)
{
    double lat1= 48.8258066, lon1 = 2.3463771000000406 , /* Personal address */
           lat2 = 48.834081, lon2 = 2.2670261000000664;  /* Work address */
    double distance;

    printf("Point n°1: %c %f° %c %f°\n", lat1>=0 ? 'N': 'S', lat1, lon1>=0 ? 'E': 'O', lon1);
    printf("Point n°2: %c %f° %c %f°\n", lat2>=0 ? 'N': 'S', lat2, lon2>=0 ? 'E': 'O', lon2);

    distance = getDistanceFromLatLonInMeter(lat1, lon1, lat2, lon2);

    printf("Distance in meters: %f m\n",distance);

    return 0;
}
