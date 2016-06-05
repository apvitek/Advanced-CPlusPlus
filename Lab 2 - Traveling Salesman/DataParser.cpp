//
//  DataParser.cpp
//  Lab2
//
//  Created by Andrea Borghi on 5/10/14.
//  Copyright (c) 2014 Andrea Borghi. All rights reserved.
//

#include "DataParser.h"

DataParser::DataParser()
{
    regexScheme = "([^<>])+";
}

DataParser::DataParser(string parsingScheme)
{
    regexScheme = parsingScheme;
}

vector<string> * DataParser::parseData(string location)
{
    vector<string> * parsedLines = new vector<string>();
    
	sregex_token_iterator end;
    
	regex pattern(regexScheme);
    
	for (sregex_token_iterator iter(location.begin(), location.end(), pattern);iter != end; ++iter){
		if ((*iter).length() > 0 && (*iter) != "\r"){
            string input = (*iter);
            
            if (!isspace(input[0]) && input[0] != '?') {
                parsedLines->push_back(input);
            }
		}
	}
    
    return parsedLines;
}