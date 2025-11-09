//
// Created by Charlie Willis on 10/23/25.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include "location.h"
#include "distance.h"
#include "MinHeap.h"
#include "mergesort.h"

using namespace std;

vector<Location> parse_real_estate(string filename) {
    /*Takes in our finished real estate CSV with corrected
    zip codes, reads it entirely, and returns a vector where each element is a location (a row on our sheet)*/

    /*MUST CITE: https://www.geeksforgeeks.org/cpp/csv-file-management-using-c/# */

    fstream file;
    file.open(filename, ios::in);
    vector<Location> location_vector;

    if (!file.is_open()){ //in case of emergency
        cout << "Real estate file did not open" << endl;
        return location_vector;
    }


    //Reading information row by row:

    vector<string> row; //Each element in this vector is a location's attributes, i.e. its date, owned/leased ..., latitude, longitude
    string line, word;
    getline(file, line);
    while (getline(file, line)) {
        row.clear();

        //Read current row information
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        if (row.size() < 18) {
            continue; // Skip to the next location if data is incomplete
        }

        //Create new location instance based on current row
        string date_ = row[0];
        string owned_ = row[1];

        //Debugging here
        int spaces_ = 0;
        try{
            spaces_ = stoi(row[2]);
        } catch(const invalid_argument&) {
            cerr << "Invalid value to convert to integer: " << row[2] << endl;
        } catch(const out_of_range&) {
            cerr << "Value out of range: " << row[2] << endl;
        }

        string active_ = row[3];
        string btype_ = row[4];

        int district_ = 0;
        try {
            district_ = stoi(row[5]);
        } catch(const invalid_argument&) {
        } catch(const out_of_range&) {
        }

        string lid_ = row[6];

        int lrid_ = 0;
        try {
            lrid_ = stoi(row[7]);
        } catch(const invalid_argument&) {
        } catch(const out_of_range&) {
        }

        string accessible_ = row[8];

        int ansi_ = 0;
        try {
            ansi_ = stoi(row[9]);
        } catch(const invalid_argument&) {
        } catch(const out_of_range&) {
        }

        string city_ = row[10];
        string county_ = row[11];
        string addr_ = row[12];
        string state_ = row[13];
        string ozip_ = row[14];
        string zip_ = row[15];

        float lat_ = 0;
        try {
            lat_ = stoi(row[16]);
        } catch(const invalid_argument&) {
        } catch(const out_of_range&) {
        }

        float long_ = 0;
        try {
            long_ = stoi(row[17]);
        } catch(const invalid_argument&) {
        } catch(const out_of_range&) {
        }

        Location current_location(date_, owned_, spaces_, active_, btype_,
                                  district_, lid_, lrid_, accessible_, ansi_, city_, county_, addr_, state_, ozip_,
                                  zip_,
                                  lat_, long_);


        //Add that instance to the vector
        location_vector.push_back(current_location);


    }

    //fin; return fully populated vector below
    return location_vector;

}


map<string, pair<float, float>> parse_us_zips(string filename){
    map<string, pair<float, float>> all_us_zips;
    
    fstream file;
    file.open(filename, ios::in);

    if (!file.is_open()){ //in case of emergency #2
        cout << "US Zips file did not open" << endl;
        return all_us_zips;
    }

    //Reading information row by row:
    vector<string> row; //Represents a unique US zip code and its corresponding lat/long
    string line, word;
    getline(file, line);
    while (getline(file, line)) {
        row.clear();

        //Read current row information
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        } //Populate row with current values being read


        string zip = row[0];
        float lat = stof(row[1]);
        float lng = stof(row[2]);
        all_us_zips[zip] = {lat, lng};  //Add to map!

    }

    return all_us_zips;
}




// MAIN FUNCTION
int main(){
    // Parse locations:
    vector<Location> locations = parse_real_estate("real_estate.csv");
    map<string, pair<float, float>> us_zips = parse_us_zips("uszipsmod.csv");
    

    //Take in zip code
    string in_zip;
    cout << "Enter your ZIP code: ";
    cin >> in_zip;
    cout << endl;

    //Determine corresponding coordinates
    pair<float, float> user_coords = us_zips[in_zip];
    float user_lat = user_coords.first;
    float user_long = user_coords.second;

    // Calculate all distances:
    calculate_all_distances(locations, user_lat, user_long);

    vector<Location> closest_locations;
    int n = 10; //This is the number of locations we will print

    //Based on the parity of the zip code we'll use heapsort or merge sort
    //Using an arbitrary quality since there's no bias between even/odd in US zip codes
    if (stoi(in_zip) % 2 == 1){
        //If it's ODD let's use merge sort
        vector<Location> sortedlocations = merge_sort(locations, in_zip, 0, locations.size()-1);
        closest_locations = get_closest(sortedlocations, n);

    } else {
        //If it's EVEN let's use heap sort
        MinHeap min_heap;
        min_heap.buildHeap(locations); //build heap based on locations vector
        closest_locations = min_heap.getTopK(n); //retrieve 10 closest locations
    }

    //Print n locations
    for (int i = 0; i < n; i++){
        Location location = closest_locations[i];
        cout << location.get_address() << ", " << location.get_city()  << ", " << location.get_state() << endl;
        cout << "This building is " << location.distance << " miles away. " << endl;
        location.describe();
        
    }



    return 0;
};