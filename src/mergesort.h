#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "location.h"
#include "distance.h"
using namespace std;

void merge_helper(vector<Location>& locations, int left, int mid, int right);

vector<Location> merge_sort(vector<Location> all_locations, string in_zip, int start, int end);
    // Description:
    // - Takes in vector of locations from CSV
    // - And returns a version of that vector, sorted by ASCENDING DISTANCE to the given zip code
    // - Parameters start and end refer to the first and last indices of the vector all_locations
    //     -> In the first call this should always be 0 and .size() - 1 respectively


vector<Location> get_closest(vector<Location> locs, int n);
