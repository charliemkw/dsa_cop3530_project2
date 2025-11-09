//
// location.cpp
//

#include <iostream>
#include "location.h"

string Location::get_date(){
    return this->date;
}

bool Location::is_owned(){
    if (this->owned == "OWNED"){
        return true;
    }
    return false;
}

int Location::get_parking_spaces(){
    return this->parking_spaces;
}

bool Location::is_active(){
    if (this->active == "ACTIVE"){
        return true;
    }
    return false;
}

string Location::get_building_type(){
    return this->building_type;
}

int Location::get_district(){
    return this->congressional_district;
}

string Location::get_id(){
    return this->location_id;
}

int Location::get_region_id(){
    return this->location_region_id;
}

string Location::get_accessibility(){
    return this->accessible;
}

int Location::get_ansi(){
    return this->ansi;
}

string Location::get_city(){
    return this->city;
}

string Location::get_county(){
    return this->county;
}

string Location::get_address(){
    return this->address;
}

string Location::get_state(){
    return this->state;
}

string Location::get_original_zip(){
    return this->original_zip;
}

string Location::get_zip(){
    return this->zipcode;
}

float Location::get_latitude(){
    return this->latitude;
}

float Location::get_longitude(){
    return this->longitude;
}

void Location::describe(){
    //Provide a description of a location based on its attributes
    //This will appear in terminal. A backup in case we cannot connect front end and backend

    string leased; 

    if (!is_active()){
        cout << "This location is unavailable for purchase." << endl << endl;
        return;
    } 

    if (this->get_date() != "0"){
        string year = this->get_date().substr(0, 4);
        cout << "This location was built in " << year << "." << endl;
    } else {
        cout << "It is not known what year this location was built." << endl;
    }

    if (this->is_owned()){
        leased = "purchase";
    } else {
        leased = "lease";
    }

    cout << "This location is available for " << leased << "." << endl;
    cout << "There are " << this->get_parking_spaces() << " parking spaces." << endl;
    cout << "ACCESSIBILITY STATUS: " << this->get_accessibility() << endl << endl;
    if (this->get_accessibility() == "Will Conform"){
        cout << " - Reach out to current owner/tenant for more information." << endl << endl;
    }

}

Location::Location(string a, string b, int c, string d, string e, int f, string g, int h, string i, int j,
        string k, string l, string m, string n, string o, string p, float q, float r){
    //Constructor
    date = a;
    owned = b;
    parking_spaces = c;
    active = d;
    building_type = e;
    congressional_district = f;
    location_id = g;
    location_region_id = h;
    accessible = i;
    ansi = j;
    city = k;
    county = l;
    address = m;
    state = n;
    original_zip = o;
    zipcode = p;
    latitude = q;
    longitude = r;
    distance = 0.0;

}

Location::Location(){
    //Default Constructor
    date = "0";
    owned = "OWNED";
    parking_spaces = 0; 
    active = "ACTIVE";
    building_type = "BUILDING"; 
    congressional_district = 0;
    location_id = "0";
    location_region_id = 0;
    accessible = "";
    ansi = 0;
    city = "Default City";
    county = "Default County";
    address = "123 Default St";
    state = "Default State";
    original_zip = "";
    zipcode = "";
    latitude = 0.0;
    longitude = 0.0;
    distance = 0.0;
}

Location& Location::operator=(const Location &other){
    //Copy assignment operator
    date = other.date;
    owned = other.owned;
    parking_spaces = other.parking_spaces;
    active = other.active;
    building_type = other.building_type;
    congressional_district = other.congressional_district;
    location_id = other.location_id;
    location_region_id = other.location_region_id;
    accessible = other.accessible;
    ansi = other.ansi;
    city = other.city;
    county = other.county;
    address = other.address;
    state = other.state;
    original_zip = other.original_zip;
    zipcode = other.zipcode;
    longitude = other.longitude;
    latitude = other.latitude;
    distance = other.distance;

    return *this;
}