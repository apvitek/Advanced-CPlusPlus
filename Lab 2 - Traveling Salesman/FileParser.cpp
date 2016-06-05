//
//  FileParser.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "FileParser.h"

vector<Location> * FileParser::parseFile(fstream& file)
{
    vector<Location> * locationVector = new vector<Location>();
    stack<string> * elementsStack = new stack<string>();
    vector<string> * parsedString = new vector<string>();
    Location newLocation;
    string toParse;
    
    while (getline(file, toParse, '\n')) {
        parsedString = parser.parseData(toParse);
        
        for (auto it = parsedString->begin(); it != parsedString->end(); ++it){
            if ((*it)[0] != '/') {
                elementsStack->push((*it));
                
            } else {
                if ((*it) == "/Address") {
                    newLocation.setAddress(elementsStack->top());
                    
                    elementsStack->pop();
                    
                } else if ((*it) == "/City"){
                    newLocation.setCity(elementsStack->top());
                    
                    elementsStack->pop();
                    
                } else if ((*it) == "/State"){
                    newLocation.setState(elementsStack->top());
                    
                    elementsStack->pop();
                    
                } else if ((*it) == "/Phone"){
                    newLocation.setPhone(elementsStack->top());
                    
                    elementsStack->pop();
                    
                } else if ((*it) == "/Latitude"){
                    string l = elementsStack->top();
                    
                    newLocation.setLatitude(atof(l.c_str()));
                    
                    elementsStack->pop();
                    
                } else if ((*it) == "/Longitude"){
                    string l = elementsStack->top();
                    
                    newLocation.setLongitude(atof(l.c_str()));
                    
                    elementsStack->pop();
                } else if ((*it) == "/Location"){
                    locationVector->push_back(newLocation);
                }
            }
        }
    }
    
    if (!elementsStack->empty()) {
        elementsStack->pop();
    }
    
    delete elementsStack;
    delete parsedString;
    
    return locationVector;
}