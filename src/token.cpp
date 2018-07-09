//
//  token.cpp
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#include <iostream>
#include <string>
#include "locale"
#include "token.h"

void Token_Stream::putback(Token t) {
    buffer = t;
    full = true;
}

/*
    Create an token or get token from buffer.
*/
Token Token_Stream::get(){
    // If token is in buffer eval first this token
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    // >> skips whitespace (space, newline, tab, etc.)
    std::cin >> ch;
    switch (ch) {
        // for print
        case ';':
            return Token{ch};
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            // put digit back into the input stream
            std::cin.putback(ch);
            double val;
            // read a floating-point number
            std::cin >> val;
            // get new token with number as kind
            return Token{s_number,val};
        }
        default:    // token for let, variables or assign
            if(isalpha(ch) || ch == s_assign) {
                
                std::string s;
                s += ch;
                
                if(ch != s_assign) {
                    
                    // Read single chars so long it is letters or digits, break if '' (whitespace)
                    // cin.get works just like >> except that it doesn’t by default skip whitespace
                    while ( std::cin.get(ch) && (isalpha(ch) || isdigit(ch))){
                        s+=ch;
                    }
                    std::cin.putback(ch);
                }
                
                if(s == s_declkey){
                    return Token{s_set};
                }
                return Token{s_decl, s}; //
            }
            throw "error";
    }
}
