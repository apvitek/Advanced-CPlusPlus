//
//  Location.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "Location.h"

Location::Location()
{
    address = "Not available";
    city = "Not available";
    state = "Not available";
    phone = "Not available";
    latitude = 0.0;
    longitude = 0.0;
}

void Location::setAddress(string a)
{
    address = a;
}

string Location::getAddress()
{
    return address;
}

void Location::setCity(string c)
{
    city = c;
}

string Location::getCity()
{
    return city;
}

void Location::setState(string s)
{
    state = s;
}

string Location::getState()
{
    return state;
};

void Location::setPhone(string p)
{
    phone = p;
};

string Location::getPhone()
{
    return phone;
};

void Location::setLatitude(double l)
{
    latitude = l;
};

double Location::getLatitute()
{
    return latitude;
};

void Location::setLongitude(double l)
{
    longitude = l;
};

double Location::getLongitude()
{
    return longitude;
};

ostream& operator << (ostream& os, const Location& loc)
{
    return os << "Address: " << loc.address << "\nCity: " << loc.city << "\nState: " << loc.state << "\nPhone: " << loc.phone << "\nLatitude: " << to_string(loc.latitude) << "\nLongitude: " << to_string(loc.longitude);
}