//
//  FileParser.h
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__FileParser__
#define __Lab2__FileParser__

#include <iostream>
#include <fstream>
#include <stack>
#include "Location.h"
#include "DataParser.h"

using namespace std;

class FileParser {
private:
    DataParser parser;
    
public:
    vector<Location> * parseFile(fstream& file);
};

#endif /* defined(__Lab2__FileParser__) */
