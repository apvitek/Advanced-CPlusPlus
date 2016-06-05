//
//  LocationContainer.h
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__LocationContainer__
#define __Lab2__LocationContainer__

#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
#include "Location.h"
#include "DistanceComputer.h"
#include "Edge.h"
#include "Vertex.h"

using namespace std;

class LocationContainer {
private:
    // Private variables
    vector<Vertex *> VertexList; // List of vertexes
    bool sortedVertex;
    
    // Private functions
    void clearVisited();
    void addNewVertex(Vertex * nVertex);
    Vertex * findVertexByLoc(Location loc);
    Vertex * walkToNext(Vertex * origin, double &distance);
    Vertex * walkToClosest (Vertex * origin, double &distance);
    Vertex * walkToOrigin(Vertex * origin, double &distance);
    
public:
    LocationContainer();
    ~LocationContainer();
    int getSize() { return (int)VertexList.size(); }
    bool isSorted() { return sortedVertex; }
    void sortVertexes();
    void readLocations(vector<Location> * locations);
    void findShortestPath();
    void permutationsToShortestPath(Location &initialLocation, Location&finalLocation, double &length);
    double distanceFromLocations(Location a, Location b);
    
    friend ostream& operator << (ostream& os, const LocationContainer& LocationContainer);
};

#endif /* defined(__Lab2__LocationContainer__) */
