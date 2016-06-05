//
//  Command.h
//  Lab0
//
//  Created by Andrea Borghi on 4/15/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab0_Command_h
#define Lab0_Command_h

class Command {
protected:
    unsigned char command;
    
public:
    virtual unsigned char getCommand() = 0;
};

#endif
