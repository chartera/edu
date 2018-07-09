#include "interpreter.h"

/*
    Simple calculator
 
    Created by Nael Tasmim
    Copyright © 2018 Nael Tasmim. All rights reserved.

 
    Revision history:
 
        Revised by Nael Tasmim  7/5/18
 
 Implementing a basic expression calculator.
 The grammer is:
 
    Calculate:
        Statement
        Print       cout
        Quit        ;
 
    Statement: (set x=3;)
        Declaration
        Expression

    Expression:
        Term
        Expression + Term
        Expression – Term
 
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary      (Not implemented)
 
    Primary:
        Number
        ( Expression )
        – Primary           (Not implemented)
        + Primary           (Not implemented)
 
    Number:
        floating-point-literal
 
 
 Input comes from cin through the Token_Stream called ts.
 */

int main() {
    // declare interpreter with default initialization though "defautl constructor"
  std::cout << "Welcome " << std::endl;
  Interpreter interpreter;
  interpreter.calculate();
  return 0;
}
