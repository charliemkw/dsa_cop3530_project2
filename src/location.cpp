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