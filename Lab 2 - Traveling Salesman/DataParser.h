//
//  DataParser.h
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__DataParser__
#define __Lab2__DataParser__

#include <iostream>
#include <regex>
#include <vector>
#include "Location.h"

using namespace std;

class DataParser {
private:
    string regexScheme;
    
public:
    DataParser();
    DataParser(string parsingScheme);
    vector<string> * parseData(string location);
};

#endif /* defined(__Lab2__DataParser__) */
