//
// distance.h
//

#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>
#include "location.h"

using namespace std;

// Earth's radius (in miles):
constexpr double EARTH_RADIUS = 3959.0;

// Convert degrees to radians:
double to_radians(double degrees);

/** Calculate the distance between two points using the Haversine formula:
* - lat1 = latitude of first point
* - long1 - longitude of first point
* - lat2 = latitude of second point
* - long2 - longitude of second point
*/
double calculate_distance(double lat1, double long1, double lat2, double long2);

/**
 * Calculates distance from a given point to a location object and updates the location's distance:
 * - location = reference to location object
 * - user_lat = user's latitude
 * - user_long = user's longitude
 */
void calculate_location_distance(Location& location, double user_lat, double user_long);

/**
 * Calculates distances for all locations in a vector
 * - locations = vector of location objects
 * - user_lat = user's latitude
 * - user_long = user's longitude
 */
void calculate_all_distances(vector<Location>& locations, double userLat, double userLon);

#endif //DISTANCE_H
