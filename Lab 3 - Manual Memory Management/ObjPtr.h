//
//  ObjPtr.h
//  Lab3
//
//  Created by Andrea Borghi on 5/25/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab3__ObjPtr__
#define __Lab3__ObjPtr__

#include <iostream>
#include "MemoryManager.h"

using namespace std;

template <class T>
class ObjPtr
{
private:
    T * pointer;
    
public:
    // Constructors
    ObjPtr(T * p = NULL) : pointer(p) {}
    ObjPtr(const ObjPtr<T>& other) : pointer(other.pointer) {}
    
    T * getData() { return pointer; }
    
    // Overloaded pointers operators
    T& operator *() { return * pointer; }
    const T& operator * () const { return * pointer; }
    
    T * operator -> () { return pointer; }
    const T * operator -> () const { return pointer; }
    
    ObjPtr<T>& operator = (ObjPtr<T>&& other)
    {
        if (this != &other) {
            if (other.getMemory()) {
                pointer = other.pointer;
            }
        }
        return * this;
    }
    
    ObjPtr<T>& operator = (T * p) { if (pointer != p)pointer = p; return * this; }
    ObjPtr<T>& operator = (T p) { if (pointer != &p)pointer = &p; return * this; }
    
    // Overloaded new and delete
    void * operator new (size_t size, MemoryManager &m) { return m.requestMemory(size); }
    
    void operator delete(void * pointer, MemoryManager &m) { m.free(pointer); }
    void operator delete(void * pointer) { return ::operator delete(pointer); }
};

#endif /* defined(__Lab3__ObjPtr__) */
