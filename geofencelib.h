#define EARTH_RADIUS 6371000
#define PI 3.14159265359
typedef enum
{
	FALSE,
	TRUE
} BOOL;

/* Distance calculation using Haversine Formula.*/
double getDistanceFromLatLonInMeter(double lat1, double lon1, double lat2, double lon2);

/* Indicates if a given position (position_lat, position_lon) is */
/* inside a circular fence.                                      */
BOOL isPointInsideFence(double fence_radius, double center_lat, double center_lon, double position_lat, double position_lon);

/* Indicates if a given position is inside a known polygon         */
/* Arg:                                                            */
/* - int number_of_intersections:                                  */
/*   how many times a ray starting from  point and going any fixed */
/*   direction intersects the edges of the polygon                 */
BOOL isPointInsidePolygon(int number_of_intersections);

