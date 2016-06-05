//
//  OperationalSpace.h
//  FinalLab
//
//  Created by Andrea Borghi on 6/21/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "Position.h"

using namespace std;

const unsigned int MAX_HEIGHT = 2000; // In mm
const unsigned int MAX_LENGTH = 3000; // In mm

class OperationalSpace {
private:
    unsigned int height;
    unsigned int length;
    
public:
    OperationalSpace(): height(MAX_HEIGHT), length(MAX_LENGTH) {}
    OperationalSpace(unsigned int h, unsigned int l) : height(h), length(l) {
        if (height > MAX_HEIGHT) height = MAX_HEIGHT;
        if (length > MAX_LENGTH) length = MAX_LENGTH;
    }
    
    unsigned int getHeight() { return height; }
    unsigned int getLength() { return length; }
};