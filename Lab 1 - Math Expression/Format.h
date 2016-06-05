//
//  Format.h
//  Lab1
//
//  Created by Andrea Borghi on 5/2/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__Format__
#define __Lab1__Format__

#include <iostream>
#include <vector>

using namespace std;

class Format {
protected:
    vector<string> * expression;
    
public:
    virtual string toString() = 0;
    virtual vector<string>::iterator getIteratorBegin();
    virtual vector<string>::iterator getIteratorEnd();
};

#endif /* defined(__Lab1__Format__) */
