#include <stdio.h>
#include "geofencelib.h"

int main (void)
{
    double lat1= 48.8258066, lon1 = 2.3463771000000406 , /* Personal address */
           lat2 = 48.834081, lon2 = 2.2670261000000664;  /* Work address */
    double distance;

    /* Presentation of the two adresses */
    printf("Point n°1: %c %f° %c %f°\n", lat1>=0 ? 'N': 'S', lat1, lon1>=0 ? 'E': 'O', lon1);
    printf("Point n°2: %c %f° %c %f°\n\n", lat2>=0 ? 'N': 'S', lat2, lon2>=0 ? 'E': 'O', lon2);

    /* Compute and display distance between the two addresses */
    distance = getDistanceFromLatLonInMeter(lat1, lon1, lat2, lon2);
    printf("Distance in meters: %f m\n\n",distance);

    /* Test if Point n°2 is inside a circular fence having Point n°1 as a center and a given radius in meters */
    double radius = distance+1;
    printf("Assuming there is a circular fence centered in\npoint n°1 (%c %f°, %c %f°)\n", 
        lat1>=0 ? 'N': 'S', lat1, lon1>=0 ? 'E': 'O', lon1);
    printf("and having a radius: %f\n", radius);
    
    printf("point n°2 (%c %f°, %c %f°) is %s the fence.\n",
        lat2>=0 ? 'N': 'S', lat2,
        lon2>=0 ? 'E': 'O', lon2, 
        TRUE == isPointInsideFence(radius, lat1, lon1, lat2, lon2) ? "inside":"outside"); 
    return 0;
}
