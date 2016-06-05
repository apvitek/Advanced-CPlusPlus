//
//  Vertex.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/12/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(Location l) {
    loc = l;
    
    status = NOT_VISITED;
}

Vertex::~Vertex() {
    adjacentVertexesList.clear();
}

enum Status Vertex::getStatus() {
    return status;
}

void Vertex::setStatus(enum Status st) {
    status = st;
}

Location Vertex::getloc() {
    return loc;
}

void Vertex::addAdjVertex(Vertex * adj, double cost) {
    Edge newEdge(this, adj, cost);
    
    adjacentVertexesList.push_back(newEdge);
}

vector<Edge>& Vertex::getadjacentVertexesList() {
    return adjacentVertexesList;
}

void Vertex::heapSortVertexes()
{
    make_heap(adjacentVertexesList.begin(), adjacentVertexesList.end());
    
    sort_heap(adjacentVertexesList.begin(), adjacentVertexesList.end());
    
    reverse(adjacentVertexesList.begin(), adjacentVertexesList.end());
}

ostream& operator << (ostream& os, const Vertex& vertex)
{
    bool printFlag = true;
    
    for(int i = 0 ; i < vertex.adjacentVertexesList.size(); i++) {
        Edge edg = vertex.adjacentVertexesList[i];
        
        if (!printFlag) {
            os << "\t\t\t\t->" << edg.getdestinationVertex()->getloc().getAddress() << " (" << edg.getCost() << " km)" << endl;
            
            printFlag = true;
            
        } else {
            os << edg.getoriginVertex()->getloc().getAddress() << "->" << edg.getdestinationVertex()->getloc().getAddress() << " (" << edg.getCost() << " km)" << endl;
        }
        
        printFlag = false;
    }
    
    return os;
}