//
//  LocationContainer.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/12/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "LocationContainer.h"

LocationContainer::LocationContainer()
{
    sortedVertex = false;
}

LocationContainer::~LocationContainer()
{
    for (int i = 0; i < VertexList.size(); ++i) {
        delete VertexList[i];
    }
    
    VertexList.clear();
}

void LocationContainer::clearVisited() {
    for(int i = 0; i < VertexList.size() ; i++) {
        VertexList[i]->setStatus(NOT_VISITED);
    }
}

void LocationContainer::addNewVertex(Vertex * nVertex)
{
    VertexList.push_back(nVertex);
    
    sortedVertex = false;
}

Vertex * LocationContainer::findVertexByLoc(Location loc)
{
    for (int i = 0 ; i < VertexList.size() ; i++) {
        if (VertexList[i]->getloc().getAddress() == loc.getAddress())
            return VertexList[i];
    }
    
    return NULL;
}

void LocationContainer::sortVertexes()
{
    if (VertexList.size() < 2) {
        return;
    }
    
    for (auto it = VertexList.begin(); it != VertexList.end(); ++it) {
        Vertex * current = (*it);
        
        current->heapSortVertexes();
    }
    
    sortedVertex = true;
}

void LocationContainer::readLocations(vector<Location> * locations) {
    // Variables declaration
    int counter = (int)locations->size();
    Location first, second;
    Location origin, destination;
    double cost;
    DistanceComputer computer;
    
    while (counter--) {
        for (auto it = locations->begin(); it != locations->end(); ++it){
            first = (* it);
            
            second = *(locations->begin() + counter);
            
            if (first.getAddress() != second.getAddress()) {
                origin = first;
                
                destination = second;
                
                cost = computer(first.getLatitute(), first.getLongitude(), second.getLatitute(), second.getLongitude());
                
                //find if a vertex for the city already exists, if so get that
                Vertex * u = findVertexByLoc(origin);
                
                if(!u){
                    u = new Vertex(origin);
                    
                    addNewVertex(u);
                }
                
                //find if a vertex for the city already exists, if so get that
                Vertex * v = findVertexByLoc(destination);
                if(!v){
                    v = new Vertex(destination);
                    
                    addNewVertex(v);
                }
                
                u->addAdjVertex(v,cost);
            }
        }
    }
}

Vertex * LocationContainer::walkToClosest(Vertex * origin, double &distance)
{
    // Variables declaration
    bool nextAvailable = false;
    Vertex * destination = nullptr;
    Location originLocation, destinationLocation;
    DistanceComputer computer;
    
    origin->setStatus(VISITED);
    
    for (int i = 0; i < origin->getadjacentVertexesList().size(); ++i) {
        if (origin->getadjacentVertexesList()[i].getdestinationVertex()->getStatus() == NOT_VISITED) {
            originLocation = origin->getloc();
            
            destination = origin->getadjacentVertexesList()[i].getdestinationVertex();
            
            destinationLocation = destination->getloc();
            
            nextAvailable = true;
            
            distance = computer(originLocation.getLatitute(), originLocation.getLongitude(), destinationLocation.getLatitute(), destinationLocation.getLongitude());
            
            cout << setprecision(2);
            cout << fixed;
            
            cout << "\nMoving " << distance << " km...\n\t" << originLocation.getAddress() << " (" << originLocation.getCity() << ") -> " << destinationLocation.getAddress() << " (" << originLocation.getCity() << ")" << endl;
            
            break;
        }
    }
    
    if (nextAvailable == false) {
        VertexList[0]->setStatus(NOT_VISITED);
        
        return VertexList[0];
    }
    
    return destination;
}

Vertex * LocationContainer::walkToNext(Vertex * origin, double &distance)
{
    // Variables declaration
    Vertex * destination = nullptr;
    Location originLocation, destinationLocation;
    DistanceComputer computer;
    
    origin->setStatus(VISITED);
    
    auto it = find(VertexList.begin(), VertexList.end(), origin);
    
    originLocation = origin->getloc();
    
    destination = *(it + 1);
    
    destinationLocation = destination->getloc();
    
    distance = computer(originLocation.getLatitute(), originLocation.getLongitude(), destinationLocation.getLatitute(), destinationLocation.getLongitude());
    
    cout << setprecision(2);
    cout << fixed;
    
    cout << "\nMoving " << distance << " km...\n\t" << originLocation.getAddress() << " (" << originLocation.getCity() << ") -> " << destinationLocation.getAddress() << " (" << originLocation.getCity() << ")" << endl;
    
    return destination;
}

Vertex * LocationContainer::walkToOrigin(Vertex * origin, double &distance)
{
    Vertex * destination = nullptr;
    Location originLocation, destinationLocation;
    DistanceComputer computer;
    
    origin->setStatus(VISITED);
    
    originLocation = origin->getloc();
    
    destination = VertexList[0];
    
    destinationLocation = destination->getloc();
    
    distance = computer(originLocation.getLatitute(), originLocation.getLongitude(), destinationLocation.getLatitute(), destinationLocation.getLongitude());
    
    cout << setprecision(2);
    cout << fixed;
    
    cout << "\nMoving " << distance << " km...\n\t" << originLocation.getAddress() << " (" << originLocation.getCity() << ") -> " << destinationLocation.getAddress() << " (" << originLocation.getCity() << ")" << endl;
    
    return destination;
}

double LocationContainer::distanceFromLocations(Location a, Location b)
{
    DistanceComputer computer;
    
    return computer(a.getLatitute(), a.getLongitude(), b.getLatitute(), b.getLongitude());
}

void LocationContainer::findShortestPath()
{
    double shortestDistance = 0.0;
    int shortestDistanceID = 0;
    
    for (int i = 0; i < VertexList.size(); ++i) {
        Vertex * current = VertexList[i];
        Vertex * previous = current;
        Vertex * startingLocation = VertexList[i];
        double distanceTravelled = 0;
        double partialDistance = 0;
        
        if (!sortedVertex) {
            sortVertexes();
        }
        
        cout << endl;
        
        for (int i = 0; i < 50; ++i) {
            cout << "*";
        }
        
        cout << endl;
        
        cout << "\nStarting from" << "...\n"<< VertexList[i]->getloc() << endl;
        
        int c = (int)VertexList.size();
        
        while (--c) {
            previous = current;
            
            current = walkToClosest(current, partialDistance);
            
            distanceTravelled += partialDistance;
        }
        
        startingLocation->setStatus(NOT_VISITED);
        
        current = walkToClosest(current, partialDistance);
        
        distanceTravelled += partialDistance;
        
        cout << "\nIn total, the travel was " << distanceTravelled << " km." << endl;
        
        if (shortestDistance == 0.0) {
            shortestDistance = distanceTravelled;
        }
        
        if (distanceTravelled < shortestDistance) {
            shortestDistance = distanceTravelled;
            
            shortestDistanceID = i;
        }
        
        clearVisited();
    }
    
    cout << "\nThe shortest distance was " << shortestDistance << " km, starting from " << VertexList[shortestDistanceID]->getloc().getAddress() << " in " << VertexList[shortestDistanceID]->getloc().getCity() << "." << endl;
}

void LocationContainer::permutationsToShortestPath(Location &initialLocation, Location&finalLocation, double &length)
{
    double shortestDistance = 0.0;
    int permCounter = 1;
    
    while (next_permutation(VertexList.begin(), VertexList.end())) {
        Vertex * current = *(VertexList.begin());
        Vertex * previous = current;
        Location initial;
        double distanceTravelled = 0;
        double partialDistance = 0;
        
        if (!sortedVertex) {
            sortVertexes();
        }
        
        initial = (* VertexList. begin())->getloc();
        
        int c = (int)VertexList.size();
        
        cout << endl;
        
        for (int i = 0; i < 50; ++i) {
            cout << "*";
        }
        
        cout << "\n- Permutation number " << permCounter << " -" << endl;
        
        cout << "\nStarting from" << "...\n"<< initial << endl;
        
        while (--c) {
            previous = current;
            
            current = walkToNext(current, partialDistance);
            
            distanceTravelled += partialDistance;
        }
        
        cout << "\nIn total, the travel was " << distanceTravelled << " km." << endl;
        
        if (shortestDistance == 0.0) {
            shortestDistance = distanceTravelled;
        }
        
        if (distanceTravelled < shortestDistance) {
            shortestDistance = distanceTravelled;
            
            finalLocation = current->getloc();
            initialLocation = VertexList[0]->getloc();
        }
        
        clearVisited();
        
        ++permCounter;
    };
    
    cout << endl;
    
    for (int i = 0; i < 50; ++i) {
        cout << "*";
    }
    
    cout << "\n\nThe shortest distance was " << shortestDistance << " km, starting from " << finalLocation.getAddress() << " in " << finalLocation.getCity() << "." << endl;
    
    length = shortestDistance;
}

ostream& operator << (ostream& os, const LocationContainer& LocationContainer)
{
    for(int i = 0; i < LocationContainer.VertexList.size(); ++i) {
        os << * LocationContainer.VertexList[i];
        
        os << endl;
    }
    
    return os;
}