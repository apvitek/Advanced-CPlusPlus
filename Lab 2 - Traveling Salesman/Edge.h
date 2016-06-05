//
//  Edge.h
//  Lab2
//
//  Created by Andrea Borghi on 5/12/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__Edge__
#define __Lab2__Edge__

#include <iostream>
#include <vector>
#include "Location.h"

using namespace std;

// Forward declaration
class Vertex;

// An object of this class represents an edge in the LocationContainer
class Edge {
private:
    Vertex * originVertex; // The originating vertex
    Vertex * destinationVertex; // The destination vertex
    double cost; // Cost of the edge
    
public:
    Edge(Vertex * firstVertex, Vertex * secVertex, unsigned inCost) {
        originVertex = firstVertex;
        
        destinationVertex = secVertex;
        
        cost = inCost;
    }
    
    Vertex * getdestinationVertex() {
        return destinationVertex;
    }
    
    Vertex * getoriginVertex() {
        return originVertex;
    }
    
    unsigned getCost() const {
        return cost;
    }
    
    inline bool operator < (const Edge& right) const { return cost > right.cost; }
    inline bool operator > (const Edge &right) const{ return (* this) < right; }
};

#endif /* defined(__Lab2__Edge__) */
