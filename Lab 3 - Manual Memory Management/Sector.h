//
//  Sector.h
//  Lab3
//
//  Created by Andrea Borghi on 5/25/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab3__Sector__
#define __Lab3__Sector__

#include <iostream>
#include <vector>

using namespace std;

class Sector
{
private:
    unsigned char * memory;
    bool allocated;
    size_t size;
    
public:
    Sector(): allocated(false), memory(NULL), size(0) {};
    void * allocate(size_t s) { size = s; allocated = true; memory = (unsigned char *)malloc(size); return memory; }
    void deallocate() { if (allocated) { allocated = false; free(memory);} }
    bool isAllocated() { return allocated; }
    size_t getSize() { return size; }
    
    void * getMemory() { return memory; }
};

#endif /* defined(__Lab3__Sector__) */
