//
// Created by Charlie Willis on 10/23/25.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "location.h"
using namespace std;

vector<Location> parse_real_estate(string filename) {
    /*Takes in our finished real estate CSV with corrected
    zip codes, reads it entirely, and returns a vector where each element is a location (a row on our sheet)*/

    /*MUST CITE: https://www.geeksforgeeks.org/cpp/csv-file-management-using-c/# */

    fstream file;
    file.open(filename, ios::in);
    vector<Location> location_vector;


    //Reading information row by row:

    vector<string> row; //Each element in this vector is a location's attributes, i.e. its date, owned/leased ..., latitude, longitude
    string line, word, temp;
    while (file >> temp) {
        row.clear();

        //Read current row information
        getline(file, line);
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        //Create new location instance based on current row
        string date_ = row[0];
        string owned_ = row[1];
        int spaces_ = stoi(row[2]);
        string active_ = row[3];
        string btype_ = row[4];
        int district_ = stoi(row[5]);
        string lid_ = row[6];
        int lrid_ = stoi(row[7]);
        string accessible_ = row[8];
        int ansi_ = stoi(row[9]);
        string city_ = row[10];
        string county_ = row[11];
        string addr_ = row[12];
        string state_ = row[13];
        string ozip_ = row[14];
        string zip_ = row[15];
        float lat_ = stof(row[16]);
        float long_ = stof(row[17]);

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

int main(){

    return 0;
};