//
//  Format.cpp
//  Lab1
//
//  Created by Andrea Borghi on 5/2/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "Format.h"

vector<string>::iterator Format::getIteratorBegin()
{
    return expression -> begin();
}

vector<string>::iterator Format::getIteratorEnd()
{
    return expression -> end();
}