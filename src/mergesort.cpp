#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "location.h"
#include "distance.h"
#include "mergesort.h"
using namespace std;

void merge_helper(vector<Location>& locations, int left, int mid, int right){
    // MUST CITE: slides 51-53 for Module 6 helped me with logic here
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Sections of locations vector to be sorted and merged
    vector<Location> x(n1);
    vector<Location> y(n2);

    // Populate sections with location instances so we aren't sorting empty vectors
    for (int i = 0; i < n1; i++){
        x[i] = locations[left + i];
    }

    for (int j = 0; j < n2; j++){
        y[j] = locations[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    // Sort locations vector by merging elements from both arrays based on each element's distance
    while (i < n1 && j < n2){
        if (x[i].distance <= y[j].distance){
            locations[k] = x[i];
            i++;
        }
        else {
            locations[k] = y[j];
            j++;
        }
        k++;
    }

    // When at least one of the sections has been fully merged, add the remaining elements to locations vector
    while (i < n1){
        locations[k] = x[i];
        i++;
        k++;
    }

    while (j < n2){
        locations[k] = y[j];
        j++;
        k++;
    }

}

void merge_sort(vector<Location>& all_locations, int start, int end){
    // Description:
    // - Takes in vector of locations from CSV
    // - And returns a version of that vector, sorted by ASCENDING DISTANCE to the given zip code
    // - Parameters start and end refer to the first and last indices of the vector all_locations
    //     -> In the first call this should always be 0 and .size() - 1 respectively


    //MUST CITE: Slides 51 to 53 of Module 6 helped with logic here

    if (start < end){
        int middle = (start + end) / 2;
        merge_sort(all_locations, start, middle);
        merge_sort(all_locations, middle + 1, end);
        merge_helper(all_locations, start, middle, end);

    }

}
