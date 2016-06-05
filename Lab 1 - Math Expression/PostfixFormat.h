//
//  PostfixFormat.h
//  Lab1
//
//  Created by Andrea Borghi on 4/27/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab1__PostfixFormat__
#define __Lab1__PostfixFormat__

#include "Format.h"

using namespace std;

class PostfixFormat : public Format {
public:
    PostfixFormat(vector<string> * exp);
    string toString();
};

#endif /* defined(__Lab1__PostfixFormat__) */
