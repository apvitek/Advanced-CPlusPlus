/*
 Andrea Borghi
 Lab 1
 */

#include <iostream>
#include "MathExpression.h"
#include "ExpressionEvaluator.h"
#include "SymbolicConverter.h"

using namespace std;

const string END_LOOP = "q";

int main(int argc, const char * argv[])
{
    // Variables declaration
    string input;
    MathExpression * expression = nullptr;
    SymbolicConverter * converter = new SymbolicConverter();
    
    while (input != END_LOOP) {
        cout << "Enter an infix expression:" << endl;
        
        getline(cin, input, '\n');
        
        cout << "\nCreating new expression..." << endl;
        expression = new MathExpression(input);
        
        cout << "\tThe infix format of the expression is " << expression -> infixToString() << "\n";
        cout << "\tThe postfix format of the expression is " << expression -> postfixToString() << "\n\n";
        
        cout << "Converting numbers to symbols..." << endl;
        converter -> convertToSymbolic(expression);
        
        cout << "\tThe infix format is now " << expression -> infixToString() << "\n";
        cout << "\tThe postfix format is now " << expression -> postfixToString() << "\n";
        
        cout << "\nConverting symbols to numbers..." << endl;
        converter -> convertToNumerical(expression);
        
        cout << "\tThe infix format is back to " << expression -> infixToString() << "\n";
        cout << "\tThe postfix format is back to " << expression -> postfixToString() << "\n";
        
        cout << "\nThe value of the expression is:" << endl;
        cout << "\t" << expression -> infixToString() << " = " << expression -> evaluate() << endl;
        
        delete expression;
        
        cout << "\nWould you like to enter another expression? If yes enter any key, if not enter '" << END_LOOP << "'.\n";
        
        getline(cin, input, '\n');
        
        cout << endl;
    }
    
    delete converter;
    
    return 0;
}