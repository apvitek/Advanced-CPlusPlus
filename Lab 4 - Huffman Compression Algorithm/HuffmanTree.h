//
//  HuffmanTree.h
//  Lab4
//
//  Created by Andrea Borghi on 5/31/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#ifndef Lab4_HuffmanTree_h
#define Lab4_HuffmanTree_h

#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include "HuffmanNode.h"

using namespace std;

class HuffmanTree {
private:
    HuffmanNode * root;
    int elementsNumber;
    int height;
    
    HuffmanNode * insertNode (HuffmanNode newNode, HuffmanNode * startingNode);
    bool findNode(HuffmanNode node, HuffmanNode * startingNode);
    void inorder(HuffmanNode * startingNode, ostream& os);
    void printIndentedSideways(HuffmanNode * startingNode, int indent, ostream& os);
    int findHeight(HuffmanNode * startingNode);
    HuffmanNode findMin(HuffmanNode * startingNode);
    HuffmanNode findMax(HuffmanNode * startingNode);
    void deleteTree(HuffmanNode * startingNode);
    
public:
    HuffmanTree() : root(NULL), elementsNumber(0) {}
    HuffmanTree(HuffmanNode * r) { root = r; }
    ~HuffmanTree() { deleteTree(root); }
    
    HuffmanNode * getRoot() { return root; }
    bool isEmpty(){ return (root); }
    int getElementsNumber() { return elementsNumber; }
    bool addNode(HuffmanNode data) { return (insertNode(data, root)); }
    bool emplaceNewNode(string s, int f) { HuffmanNode data(s,f); return (insertNode(data, root)); }
    bool searchNode (HuffmanNode data) { return (findNode(data, root)); }
    void displayTree(ostream& os) {printIndentedSideways(root, 0, os); }
    void printInorder(ostream& os) { inorder(root, os); }
    int getHeight() { return height; };
    HuffmanNode getSmallest() { return findMin(root); }
    HuffmanNode getLargest() { return findMax(root); }
};

HuffmanNode * HuffmanTree::insertNode(HuffmanNode newNode, HuffmanNode * startingNode)
{
    if (!startingNode) {
        startingNode = new HuffmanNode(newNode);
        
        if (!root) root = startingNode;
        
        ++elementsNumber;
        
        height = findHeight(root);
        
    } else if (* startingNode < newNode) {
        startingNode->right = insertNode (newNode, startingNode->right);
        
    } else {
        startingNode->left = insertNode (newNode, startingNode->left);
    }
    
    return startingNode;
}

bool HuffmanTree::findNode(HuffmanNode node, HuffmanNode * startingNode)
{
    bool result;
    
    if (!startingNode) {
        result = false;
        
    } else if (node == * startingNode){
        result = true;
        
    } else if (node > * startingNode) {
        result = findNode(node, startingNode->right);

    } else if (node < * startingNode) {
        result = findNode(node, startingNode->left);
    }
    
    return result;
}

void HuffmanTree::inorder(HuffmanNode * startingNode, ostream& os)
{
    if (!startingNode) return;
    
    inorder(startingNode->left, os);
    
    os << "\t" << * startingNode << "\n";
    
    inorder(startingNode->right, os);
}

HuffmanNode HuffmanTree::findMin(HuffmanNode * startingNode)
{
    HuffmanNode data;
    
    if (startingNode != NULL) {
        if (startingNode->left != NULL) {
            data = findMin(startingNode->left);

        } else {
            data = * startingNode;
        }
    }
    
    return data;
}

HuffmanNode HuffmanTree::findMax(HuffmanNode * startingNode)
{
    HuffmanNode data;
    
    if (startingNode != NULL) {
        if (startingNode->right != NULL) {
            data = findMax(startingNode->right);
            
        } else {
            data = * startingNode;
        }
    }
    
    return data;
}

void HuffmanTree::deleteTree(HuffmanNode * startingNode)
{
    if (!startingNode) return;
    
    deleteTree(startingNode->left);

    deleteTree(startingNode->right);
    
    delete startingNode;
}

int HuffmanTree::findHeight(HuffmanNode * startingNode)
{
    if (!startingNode) return -1;
    
    int leftHeight = findHeight(startingNode->left);
    
    int rightHeight = findHeight(startingNode->right);
    
    return max(leftHeight, rightHeight) + 1;
}

void HuffmanTree::printIndentedSideways(HuffmanNode * startingNode, int indent, ostream& os)
{
    if (startingNode) {
        indent += 2;
        
        printIndentedSideways(startingNode->right, indent, os);
        
        os << setw(indent * 3) << indent / 2 << ". " << * startingNode << endl;
        
        printIndentedSideways(startingNode->left, indent, os);
    }
}

#endif
