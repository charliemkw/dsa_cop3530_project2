//
// Created by vigwe on 10/23/2025.
// location.h
//

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
using namespace std;

class Location {

    private: //Making information private so that they cannot be changed
        string date; //A; If unknown, this is "0".
        string owned; //B; OWNED or LEASED
        //^ making this a str so its easier to parse through csv but can change to bool if anyone wants :) 
        int parking_spaces; //C
        string active; //D; ACTIVE or INACTIVE
        string building_type; //E
        int congressional_district; //F
        string location_id; //G
        int location_region_id; //H; not sure what this represents?
        string accessible; //I; "Will Conform" or "Yes" or "No"
        int ansi; //J
        string city; //K
        string county; //L
        string address; //M
        string state; //N
        string original_zip; //O
        string zipcode; //P; zip code with proper length; use this

    public: 

    //Getters
    string get_date(); //A

    bool is_owned(); //B

    int get_parking_spaces(); //C

    bool is_active(); //D

    string get_building_type(); //E

    int get_district(); //F; congressional district

    string get_id(); //G; location id

    int get_region_id(); //H; location region ID

    string get_accessibility(); //I

    int get_ansi(); //J

    string get_city(); //K

    string get_county(); //L

    string get_state(); //N

    string get_original_zip(); //O

    string get_zip(); //P; This is our corrected zip code

    float get_latitude(); //Q

    float get_longitude(); //R

    void describe(); 

    double distance; // need to be accessed in minHeap
    float latitude; //Q
    float longitude; //R

    string get_address(); //M

    //Parameterizd Constructor
    Location(string a, string b, int c, string d, string e, int f, string g, int h, string i, int j,
             string k, string l, string m, string n, string o, string p, float q, float r);

    //Default constructor
    Location();
    

    Location& operator=(const Location &other); //Copy assignment operator; use for mergesort

};

#endif // LOCATION_H