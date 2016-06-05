//
//  main.cpp
//  Lab4
//
//  Created by Andrea Borghi on 5/31/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "CharacterFrequencyCounter.h"
#include "HuffmanTree.h"
#include "HuffmanAlgorithm.h"

using namespace std;

int main(int argc, const char * argv[])
{
    string input = "mississippi river";
    
    cout << "Testing with string \"" << input << "\"." << endl;
    
    CharacterFrequencyCounter counter;
    
    counter.parseSingleLine(input);
    
    cout << "\nThe frequencies of the characters in " << input << " are:" << endl;
    
    counter.printCharactersAndFrequencies();
    
    cout << "\nThe encoded representation of " << input << " with the algorithm is:" << endl;
    
    cout << counter.getBitsSequence() << endl << endl;
    
    map<char,int> testMap = counter.getFrequencyMap();
    
    HuffmanAlgorithm testAlgorithm(&testMap);
    
    string encoded, result;
    string testInstructions = counter.getBitsSequence();
    
    testAlgorithm.encodeString(input, testAlgorithm.getTreeRoot(), encoded);
    
    cout << "The coded string is " << encoded << endl;
    
    result = testAlgorithm.decryptSingleLine(encoded);
    
    cout << "The decoded string is " << result << endl;
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    
    cout << "Now let's use the algorithm to decrypt the file Huffman.bin!" << endl;
    
    fstream inputFileForTree("/Users/andreaborghi/Documents/DAC - Advanced C++/Lab4/Lab4/Kennedy.txt", ios::in);
    fstream inputFileToDecode("/Users/andreaborghi/Documents/DAC - Advanced C++/Lab4/Lab4/Huffman.bin", ios::in | ios::binary);
    
    CharacterFrequencyCounter counterForTree;
    CharacterFrequencyCounter counterForDecoding;
    
    counterForTree.parseFile(inputFileForTree);
    
    map<char, int> frequencyMap = counterForTree.getFrequencyMap();
    
    cout << "Here are the characters in the input file and their frequencies:" << endl;
    
    counterForTree.printCharactersAndFrequencies();
    
    cout << "Now the Huffman codes will be calculated." << endl;
    
    HuffmanAlgorithm algorithm(&frequencyMap);
    
    counterForDecoding.parseFile(inputFileToDecode);
    
    string instructions = counterForDecoding.getBitsSequence();
    
    cout << "\nAnd here is the final result, the decrypted file!" << endl << endl;

    cout << algorithm.decryptSingleLine(instructions) << endl;
    
    inputFileForTree.close();
    inputFileToDecode.close();
    
    return 0;
}