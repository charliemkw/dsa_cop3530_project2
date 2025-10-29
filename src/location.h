//
// Created by vigwe on 10/23/2025.
//
#include <iostream>
using namespace std;

class Location {
    string date; //A; If unknown, this is "0".
    string owned; //B; OWNED or LEASED
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
    string original_zip; //O; DO NOT NEED THIS 
    string zipcode; //P; zip code with proper length
    float latitude; //Q
    float longitude; //R


    Location(string a, string b, int c, string d, string e, int f, string g, int h, string i, int j, 
        string k, string l, string m, string n, string o, string p, float q, float r){
            //Constructor 
            date = a;
            owned = b;
            parking_spaces = c;
            active = d;
            building_type = e;
            congressional_district = f;
            
        }
};