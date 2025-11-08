//
// distance.cpp
// Implementation of distance calculation
//

#include <cmath>
#include "distance.h"

double to_radians(double degrees) {
  // radians = degrees * pi / 180
  // I used an approximation for pi instead of M_PI because it made my compiler freak out sorry
  double radians = degrees * 3.14159265 / 180.0;
  return radians;
}

/**
* Based on/Adapted from Geeks for Geeks:
* https://www.geeksforgeeks.org/dsa/haversine-formula-to-find-distance-between-two-points-on-a-sphere/
*/
double calculate_distance(double lat1, double long1, double lat2, double long2) {
  // First convert latitude and longitude from degrees to radians:
  double lat1_rad = to_radians(lat1);
  double long1_rad = to_radians(long1);
  double lat2_rad = to_radians(lat2);
  double long2_rad = to_radians(long2);

  // Calculate the difference between lats and longs:
  double lat_diff = lat2_rad - lat1_rad;
  double long_diff = long2_rad - long1_rad;

  // Use the Haversine formula:
  double a = sin(lat_diff / 2.0) * sin(lat_diff / 2.0) +
               cos(lat1_rad) * cos(lat2_rad) *
               sin(long_diff/ 2.0) * sin(long_diff / 2.0);

  double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  // Calculate distance:
  double distance = EARTH_RADIUS * c;

  return distance;
}

void calculate_location_distance(Location& location, double user_lat, double user_long) {
  // Get location latitude and longitude:
  double location_lat = location.get_latitude();
  double location_long = location.get_longitude();

  // Calculate distance between user location and database location:
  // Assign the resulting value to the location's distance variable:
  location.distance = calculate_distance(user_lat, user_long, location_lat, location_long);
}

void calculate_all_distances(vector<Location>& locations, double user_lat, double user_long) {
  // Calculate distances between user location and all database locations:
  // Iterates through locations vector and calls calculate_location_distance for each location:
  for (size_t i = 0; i < locations.size(); i++) {
    calculate_location_distance(locations[i], user_lat, user_long);
  }
}




