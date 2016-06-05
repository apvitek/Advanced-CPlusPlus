//
//  MemoryPool.h
//  Lab3
//
//  Created by Andrea Borghi on 5/30/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab3_MemoryPool_h
#define Lab3_MemoryPool_h

include <iostream>
#include <memory>
#include "Sector.h"

using namespace std;

const int POOL_SIZE = 1000;

class MemoryPool
{
private:
    unsigned char * pool [POOL_SIZE];
    int allocatedBlocks;
    int nextAvailableBlockIndex;
    int holesInMemory;
    
public:
    MemoryPool(size_t size) : sectorList(allocatedBlocks(0), nextAvailableBlockIndex(0), holesInMemory(0){};
    ~MemoryPool() { delete pool; }
    void * requestMemory(size_t size);
    void free(void * toFree);
    bool compressFreeMemory();
    bool resetMemory();
    int getCountAllocatedBlocks() { return allocatedBlocks; }
    void printMemory(ostream& os) const;
    
    friend ostream& operator << (ostream& os, const MemoryPool& m);
};

void * MemoryPool::requestMemory(size_t size)
{
    if (nextAvailableBlockIndex == POOL_SIZE - 1) {
        cout << "Out of memory!" << endl;
        
        return NULL;
    }
    
    void * ptr = NULL;
    
    for (int i = nextAvailableBlockIndex; i < POOL_SIZE; ++i) {
        if (!(*sectorList)[i].isAllocated()) {
            ptr = (*sectorList)[i].allocate(size);
            
            ++allocatedBlocks;
            
            if (i < nextAvailableBlockIndex) nextAvailableBlockIndex = i;
            
            break;
        }
    }
    
    return ptr;
}

void MemoryPool::free(void * toFree) {
    if (allocatedBlocks == 0) return;
    
    int i = 0;
    
    for (auto it = sectorList->begin(); it != sectorList->end(); ++it) {
        ++i;
        
        if (toFree == (*it).getMemory()) {
            (*it).deallocate();
            
            --allocatedBlocks;
            
            ++holesInMemory;
            
            if (i < nextAvailableBlockIndex) nextAvailableBlockIndex = i;
            
            break;
        }
    }
}

bool MemoryPool::compressFreeMemory()
{
    if (allocatedBlocks == 0) return false;
    
    int i = 0;
    
    for (auto it = sectorList->begin(); it != sectorList->end(); ++it) {
        Sector * current = &(*it);
        
        if (!current->isAllocated()) {
            sectorList->erase(it);
            
            --holesInMemory;
            
            sectorList->push_back(* new Sector);
            
            // Roll back iterator
            --it;
        }
        
        if (holesInMemory == 0) {
            if (i < nextAvailableBlockIndex) nextAvailableBlockIndex = i;
            
            break;
        }
        
        ++i;
    }
    
    return true;
}

bool MemoryPool::resetMemory()
{
    for (auto it = sectorList->begin(); it != sectorList->end(); ++it) {
        Sector * current = &(*it);
        
        if (current->isAllocated()) current->deallocate();
    }
    
    allocatedBlocks = 0;
    
    holesInMemory = 0;
    
    nextAvailableBlockIndex = 0;
    
    return true;
}

void MemoryPool::printMemory(ostream& os) const
{
    for (int i = 0; i < sectorList->size(); ++i) (* sectorList)[i].isAllocated() ? os << "+" : os << "-";
}

ostream& operator << (ostream& os, const MemoryPool& m)
{
    m.printMemory(os);
    
    return os;
}

#endif
