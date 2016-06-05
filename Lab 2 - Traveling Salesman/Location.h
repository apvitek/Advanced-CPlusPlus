//
//  Location.h
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__Location__
#define __Lab2__Location__

#include <iostream>

using namespace std;

class Location {
private:
    string address;
    string city;
    string state;
    string phone;
    double latitude;
    double longitude;
    
public:
    Location();
    void setAddress(string a);
    string getAddress();
    void setCity(string c);
    string getCity();
    void setState(string s);
    string getState();
    void setPhone(string p);
    string getPhone();
    void setLatitude(double l);
    double getLatitute();
    void setLongitude(double l);
    double getLongitude();
    
    friend ostream& operator << (ostream& os, const Location& loc);
};

#endif /* defined(__Lab2__Location__) */
