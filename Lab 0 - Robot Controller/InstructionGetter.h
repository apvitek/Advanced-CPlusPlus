//
//  InstructionGetter.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab0_InstructionGetter_h
#define Lab0_InstructionGetter_h

#include <String.h>

using namespace std;

class InstructionGetter {
public:
    virtual string getInstruction() = 0;
    virtual ~InstructionGetter(){};
};

#endif
