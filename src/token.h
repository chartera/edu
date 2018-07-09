//
//  token.h
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#ifndef token_h
#define token_h

#include <iostream>
#include "symbols.h"

class Token {
public:
    char kind;
    double value;
    std::string name;
    
    Token() {}
    
    Token(char kind) : kind{kind} { }                                // initialize kind with ch
    Token(char kind, double val) : kind{kind}, value{val} { }    // initialize kind
    Token(char kind, std::string n) : kind{kind}, name{n} { }
};

class Token_Stream {
public:
    Token get();
    void putback(Token t);
private:
    bool full{false};
    Token buffer;
};



#endif /* token_h */
