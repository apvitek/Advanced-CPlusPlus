//
//  MemoryManager.cpp
//  Lab3
//
//  Created by Andrea Borghi on 5/25/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "MemoryManager.h"

void * MemoryManager::requestMemory(size_t size)
{
    void * ptr = nullptr;
    
    for (auto it = sectorList->begin(); it != sectorList->end(); ++it) {
        Sector * current = &(*it);
        
        if (!current->isAllocated()) {
            ptr = current->allocate();
            
            ++allocatedBlocks;
            
            break;
        }
    }
    
    return ptr;
}

bool MemoryManager::compressFreeMemory()
{
    return true;
}

bool MemoryManager::resetMemory()
{
    for (auto it = sectorList->begin(); it != sectorList->end(); ++it) {
        Sector * current = &(*it);
        
        if (!current->isAllocated()) {
            current->deallocate();
            
            --allocatedBlocks;
        }
    }
    
    return true;
}