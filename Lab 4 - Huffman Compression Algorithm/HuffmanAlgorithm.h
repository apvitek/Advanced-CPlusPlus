//
//  HuffmanAlgorithm.h
//  Lab4
//
//  Created by Andrea Borghi on 6/1/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef __Lab4__HuffmanAlgorithm__
#define __Lab4__HuffmanAlgorithm__

#include <iostream>
#include <sstream>
#include <map>
#include "HuffmanTree.h"

using namespace std;

class HuffmanAlgorithm {
private:
    HuffmanTree * tree;
    map<char, int> * inputMap;
    vector<HuffmanNode> branchContainer;
    map<string, string> * conversionTable;
    
    void sortBranchContainer();
    void generateCodes(HuffmanNode * node, string code);
    string decryptString(string& inputString);
    //void decryptString(string &instructions, HuffmanNode * node, string& result, char * walker);
    
public:
    HuffmanAlgorithm(std::map<char, int> * input) : inputMap(input){ conversionTable = new map<string,string>(); startAlgorithm(); };
    //~HuffmanAlgorithm() { delete tree; delete inputMap; delete conversionTable; }
    
    void startAlgorithm();
    void encodeString(string& original, HuffmanNode * node, string& result);
    string decryptFile(fstream &inputString, string instructions);
    string decryptSingleLine(string inputLine) { return decryptString(inputLine); }
    
    HuffmanNode * getTreeRoot() { return tree->getRoot(); }
};

void HuffmanAlgorithm::startAlgorithm()
{
    for (auto it = inputMap->begin(); it != inputMap->end(); ++it) {
        HuffmanNode * newNode = new HuffmanNode();
        
        stringstream s;
        s << it->first;
        
        newNode->setSymbol(s.str());
        newNode->setFrequency(it->second);
        
        branchContainer.push_back(* newNode);
    }
    
    while (branchContainer.size() > 1) {
        sortBranchContainer();
        
        HuffmanNode * leftNode = new HuffmanNode(*branchContainer.begin());
        
        //cout << "L: " << leftNode->getSymbol() << " => " << leftNode->getFrequency() << endl;
        
        branchContainer.erase(branchContainer.begin());
        
        HuffmanNode * rightNode = new HuffmanNode(*branchContainer.begin());
        
        //cout << "R: " << rightNode->getSymbol() << " => " << rightNode->getFrequency() << endl;
        
        branchContainer.erase(branchContainer.begin());
        
        HuffmanNodeBranch * newBranch = new HuffmanNodeBranch();
        
        newBranch->setChildren(leftNode, rightNode);
        
        newBranch->setSymbol(newBranch->getSymbol());
        newBranch->setFrequency(newBranch->getFrequency());
        
        branchContainer.push_back(* newBranch);
        
        //cout << "New branch: " << newBranch->getFrequency() << " => " << newBranch->getSymbol() << endl << endl;
    }
    
    tree = new HuffmanTree(&*branchContainer.begin());
    
    string code = "";
    
    generateCodes(tree->getRoot(), code);
}

void HuffmanAlgorithm::generateCodes(HuffmanNode * node, string code)
{
    if (node->left == NULL){
        node->setCode(code);
        
        cout << "The code for " << node->getSymbol() << " is " << code << endl;
        
        conversionTable->emplace(node->getSymbol(), code);
        
    } else {
        generateCodes(node->left, code + "0");
        generateCodes(node->right, code + "1");
    }
}

void HuffmanAlgorithm::sortBranchContainer()
{
    sort(branchContainer.begin(), branchContainer.end(), [](const HuffmanNode lhs, const HuffmanNode rhs) -> bool
         {
             if (lhs.getFrequency() != rhs.getFrequency()) return lhs.getFrequency() < rhs.getFrequency();
             
             return lhs.getSymbol().length() < rhs.getSymbol().length();
         });
}

string HuffmanAlgorithm::decryptString(string & inputString)
{
    HuffmanNode * node;
    string result;
    char * walker = &inputString[0];
    
    while (*walker != *inputString.end()) {
        node = tree->getRoot();
        
        while (node->left || node->right) {
            if (*walker == '0') {
                node = node->left;
                ++walker;
                
            } else if (*walker == '1') {
                node = node->right;
                ++walker;
                
            } else {
                cout << "*** INVALID INSTRUCTION! ***";
                break;
            }
        }
        
        result += node->getSymbol();
    }
    
    return result;
}

string HuffmanAlgorithm::decryptFile(fstream &inputFile, string instructions)
{
    string inputLine, result;
    
    while (getline(inputFile, inputLine)) result += decryptString(inputLine);
    
    return result;
}

void HuffmanAlgorithm::encodeString(string& original, HuffmanNode * node, string& result)
{
    for (int i = 0; i < original.length(); ++i) {
        string current;
        
        current += original[i];
        
        auto it = conversionTable->find(current);
        
        result += it->second;
    }
}

/* Recursive version, crashing
 void HuffmanAlgorithm::decryptString(string &instructions, HuffmanNode * node, string& result, char * walker)
 {
 if (node->leaf) {
 if (*walker != *instructions.end()) {
 result += node->getSymbol();
 
 //cout << "The instruction " << node->getCode() << " returned " << node->getSymbol() << endl;
 
 cout << result << endl << endl;
 
 //cout << "\t*** Current instructions length: " << instructions.length() << " ***" << endl;
 
 decryptString(instructions, tree->getRoot(), result, walker);
 } else {
 result += node->getSymbol();
 }
 
 } else {
 if (*walker == '0') {
 walker++;
 
 if (node->left) {
 decryptString(instructions, node->left, result, walker);
 
 } else {
 cout << "*** BAD INSTRUCTION *** " << endl;
 decryptString(instructions, tree->getRoot(), result, walker);
 }
 
 } else {
 walker++;
 
 if (node->right) {
 decryptString(instructions, node->right, result, walker);
 
 } else {
 cout << "*** BAD INSTRUCTION *** " << endl;
 decryptString(instructions, tree->getRoot(), result, walker);
 }
 }
 }
 }
 */

#endif /* defined(__Lab4__HuffmanAlgorithm__) */
