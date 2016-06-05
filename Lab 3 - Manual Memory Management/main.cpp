//
//  main.cpp
//  Lab3
//
//  Created by Andrea Borghi on 5/25/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include "ObjPtr.h"
#include "MemoryManager.h"

using namespace std;

const int NUM_ELEMS = 3000;

int main(int argc, const char * argv[])
{
    MemoryManager * manager = new MemoryManager(NUM_ELEMS);
    
    vector<ObjPtr<int> *> intVector(NUM_ELEMS * 2);
    vector<ObjPtr<char> *> charVector(NUM_ELEMS * 2);
    vector<ObjPtr<double> *> doubleVector(NUM_ELEMS * 2);
    
    for (int i = 0; i < NUM_ELEMS / 3; ++i) intVector.push_back(new (* manager) ObjPtr<int>());
    for (int i = 0; i < NUM_ELEMS / 3; ++i) charVector.push_back(new (* manager) ObjPtr<char>());
    for (int i = 0; i < NUM_ELEMS / 3; ++i) doubleVector.push_back(new (* manager) ObjPtr<double>());
    
    cout << "Allocating " << NUM_ELEMS / 3 << " ints, double and chars in Memory Manager." << endl;
    
    cout << "The total allocated sectors are " << manager->getCountAllocatedBlocks() << "." << endl;
    
    cout << * manager << endl;
    
    cout << "\nDeleting few elements from memory..." << endl;
    
    srand(0);
    
    for (int i = 0; i < intVector.size(); ++i) {
        int index = rand() % intVector.size() - i;
        
        ObjPtr<int>::operator delete (intVector[index], * manager);
        intVector.erase(intVector.begin() + index);
        
        ObjPtr<char>::operator delete (charVector[index], * manager);
        charVector.erase(charVector.begin() + index);
        
        ObjPtr<double>::operator delete (doubleVector[index], * manager);
        doubleVector.erase(doubleVector.begin() + index);
    }
    
    cout << "There are now " << manager->getCountAllocatedBlocks() << " elements left." << endl;
    
    cout << * manager << endl;
    
    int toAdd = NUM_ELEMS - manager->getCountAllocatedBlocks();
    
    cout << "\nAdding " << toAdd / 2 << " new elements to memory..." << endl;
    
    for (int i = 0; i < toAdd / 6; ++i) intVector.push_back(new (* manager) ObjPtr<int>());
    for (int i = 0; i < toAdd / 6; ++i) charVector.push_back(new (* manager) ObjPtr<char>());
    for (int i = 0; i < toAdd / 6; ++i) doubleVector.push_back(new (* manager) ObjPtr<double>());
    
    cout << "There now are " << manager->getCountAllocatedBlocks() << " allocated blocks." << endl;
    
    cout << * manager << endl;
    
    cout << "\nCompressing memory..." << endl;
    
    manager->compressFreeMemory();
    
    cout << "There are still " << manager->getCountAllocatedBlocks() << " allocated blocks." << endl;
    
    cout << * manager << endl;
    
    cout << "\nResetting the memory..." << endl;
    
    manager->resetMemory();
    
    cout << "There are now " << manager->getCountAllocatedBlocks() << " allocated blocks." << endl;
    
    cout << * manager << endl;
    
    delete manager;
    
    return 0;
}