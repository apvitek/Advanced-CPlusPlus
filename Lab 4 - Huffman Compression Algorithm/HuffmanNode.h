//
//  HuffmanNode.h
//  Lab4
//
//  Created by Andrea Borghi on 5/31/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab4_HuffmanNode_h
#define Lab4_HuffmanNode_h

#include <iostream>

using namespace std;

class HuffmanNode {
private:
    string symbol;
    int frequency;
    string code;
    
public:
    HuffmanNode * left; // To store the address of the left child
    HuffmanNode * right; // To store the address of the right child
    bool leaf;
    
    HuffmanNode() { symbol = ""; frequency = -1; left = NULL; right = NULL; leaf = true; }
    HuffmanNode(string s, int f) { symbol = s; frequency = f; left = NULL; right = NULL; }
    
    string getSymbol() const { return symbol; }
    void setSymbol(string s) { symbol = s; }
    int getFrequency() const { return frequency; }
    void setFrequency(int f) { frequency = f; }
    void addToCode(string &num) { code += num; }
    void setCode(string c) { code = c; }
    string getCode() { return code; }
    
    friend ostream& operator << (ostream& os, const HuffmanNode& node) { return os << node.getSymbol() << " => " << node.getFrequency(); }
    
    bool operator < (const HuffmanNode &right) const { if (this->frequency != right.frequency){ return this->frequency < right.frequency;} return this->symbol < right.symbol; }
    bool operator > (const HuffmanNode &right) const { return !((* this) < right); }
    bool operator <= (const HuffmanNode &right)const { return !((* this) > right); }
    bool operator >= (const HuffmanNode &right)const { return !((* this) < right); }
    bool operator == (const HuffmanNode &right)const { return this->symbol == right.symbol; }
    bool operator != (const HuffmanNode &right)const { return !((*this) == right); }
};

class HuffmanNodeBranch : public HuffmanNode {
public:
    HuffmanNodeBranch() : HuffmanNode() { leaf = false; }
    
    string getSymbol() {
        string result;
        
        if (left) result += left->getSymbol();
        if (right) result += right->getSymbol();
        
        return result;
    }
    
    int getFrequency() { return left->getFrequency() + right->getFrequency(); }
    
    void setChildren(HuffmanNode * l, HuffmanNode * r) { left = l; right = r; }
};

#endif
