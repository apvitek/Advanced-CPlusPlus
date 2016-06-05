//
//  MemoryManager.h
//  Lab3
//
//  Created by Andrea Borghi on 5/25/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab3__MemoryManager__
#define __Lab3__MemoryManager__

#include <iostream>
#include <memory>
#include "Sector.h"

using namespace std;

class MemoryManager
{
private:
    vector<Sector> * sectorList;
    int allocatedBlocks;
    int nextAvailableBlockIndex;
    int holesInMemory;
    
public:
    MemoryManager(size_t size) : sectorList(new vector<Sector>(size)), allocatedBlocks(0), nextAvailableBlockIndex(0), holesInMemory(0){};
    ~MemoryManager() { delete sectorList; }
    void * requestMemory(size_t size);
    void free(void * toFree);
    bool compressFreeMemory();
    bool resetMemory();
    int getCountAllocatedBlocks() { return allocatedBlocks; }
    void printMemory(ostream& os) const;
    
    friend ostream& operator << (ostream& os, const MemoryManager& m);
};

void * MemoryManager::requestMemory(size_t size)
{
    if (nextAvailableBlockIndex == sectorList->size() - 1) {
        cout << "Out of memory!" << endl;
        
        return NULL;
    }
    
    void * ptr = NULL;
    
    for (int i = nextAvailableBlockIndex; i < sectorList->size(); ++i) {
        if (!(*sectorList)[i].isAllocated()) {
            ptr = (*sectorList)[i].allocate(size);
            
            ++allocatedBlocks;
            
            if (i < nextAvailableBlockIndex) nextAvailableBlockIndex = i;
            
            break;
        }
    }
    
    return ptr;
}

void MemoryManager::free(void * toFree) {
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

bool MemoryManager::compressFreeMemory()
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

bool MemoryManager::resetMemory()
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

void MemoryManager::printMemory(ostream& os) const
{
    for (int i = 0; i < sectorList->size(); ++i) (* sectorList)[i].isAllocated() ? os << "+" : os << "-";
}

ostream& operator << (ostream& os, const MemoryManager& m)
{
    m.printMemory(os);
    
    return os;
}

#endif /* defined(__Lab3__MemoryManager__) */
