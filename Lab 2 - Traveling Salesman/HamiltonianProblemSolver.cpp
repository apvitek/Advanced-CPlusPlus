//
//  HamiltonianProblemSolver.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/16/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "HamiltonianProblemSolver.h"

HamiltonianProblemSolver::HamiltonianProblemSolver(int maxProblemSize)
{
    divisor = new ProblemDivisor(maxProblemSize);
}

HamiltonianProblemSolver::~HamiltonianProblemSolver()
{
    delete divisor;
}

void HamiltonianProblemSolver::solveProblem(vector<Location> *parsedStrings)
{
    LocationContainer completeLocationContainer;
    
    vector<vector<Location>> dividedData = divisor->breakProblem(parsedStrings);
    
    completeLocationContainer.readLocations(parsedStrings);
    
    vector<LocationContainer> locationContainerVectors (dividedData.size());
    
    cout << "The locations will now be divided in smaller lists." << endl << endl;
    
    for (int i = 0; i < dividedData.size(); ++i) {
        locationContainerVectors[i].readLocations(&dividedData[i]);
        
        cout << "Here is partial location list number " << i + 1 << " (" << locationContainerVectors[i].getSize() << " elements):" << endl << endl;
        cout << locationContainerVectors[i] << endl;
    }
    
    cout << "Now let's see the permutations:" << endl;
    
    vector<Location> initialLocVector (locationContainerVectors.size());
    vector<Location> finalLocVector (locationContainerVectors.size());
    vector<double> finalCoordVector (locationContainerVectors.size());
    
    for (int i = 0; i < locationContainerVectors.size(); ++i) {
        locationContainerVectors[i].permutationsToShortestPath(initialLocVector[i], finalLocVector[i], finalCoordVector[i]);
    }
    
    LocationContainer finalLocationContainer;
    
    finalLocationContainer.readLocations(&finalLocVector);
    
    cout << "\nThe final LocationContainer is:" << endl;
    cout << finalLocationContainer << endl;
    
    double finalDistance = 0;
    Location initialLocation, finalLocation;
    
    cout << "\nAnd the final answer is..." << endl;
    finalLocationContainer.permutationsToShortestPath(initialLocation, finalLocation, finalDistance);
    
    for (int i = 0; i < finalCoordVector.size(); ++i) {
        finalDistance += finalCoordVector[i];
    }
    
    // Add the distance between the final and the initial location
    // It is not added in the partial permutations as it would violate
    // the principle that every vertex is visited only once
    finalDistance += finalLocationContainer.distanceFromLocations(initialLocation, finalLocation);
    
    cout << "\nThe ideal path would be: " << endl;
    
    completeLocationContainer.findShortestPath();
    
    cout << endl;
    
    for (int i = 0; i < 50; ++i) {
        cout << "*";
    }
    
    cout << "\n\nThe final total distance was " << finalDistance << " km, starting from " << initialLocation.getAddress() << " in " << finalLocation.getCity() << "." << endl;
}