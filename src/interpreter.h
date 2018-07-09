//
//  interpreter.h
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#ifndef interpreter_h
#define interpreter_h

#include "token.h"
#include "variable.h"

class Interpreter{
public:
    void calculate();
private:
    Token_Stream ts;
    Variable variable;
    double primary();
    double term();
    double expression();
    double declaration();
    double statement();
};

#endif /* interpreter_h */
