//
//  Vertex.h
//  Lab2
//
//  Created by Andrea Borghi on 5/12/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab2__Vertex__
#define __Lab2__Vertex__

#include <iostream>
#include <vector>
#include "Location.h"
#include "Edge.h"

using namespace std;

// enum for the status of a Vertex
enum Status {
    NOT_VISITED,
    VISITED
};

// Forward declaration
class Edge;

// An object of this class holds a vertex of the LocationContainer
class Vertex {
private:
    Location loc;
    vector<Edge> adjacentVertexesList; // To store the list of Vertexes connected to "this" Vertex
    enum Status status;
    
public:
    Vertex(Location l);
    ~Vertex();
    enum Status getStatus();
    void setStatus(enum Status st);
    Location getloc();
    void addAdjVertex(Vertex * adj, double cost);
    vector<Edge>& getadjacentVertexesList();
    void heapSortVertexes();
    
    friend ostream& operator << (ostream& os, const Vertex& vertex);
};

#endif /* defined(__Lab2__Vertex__) */
