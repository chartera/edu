//
//  interpreter.cpp
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#include "interpreter.h"
#include <iostream>

double Interpreter::primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                throw "error";
            return d;
        }
        case s_number:
            return t.value;
        case s_decl:
        {
            double val = variable.get_value(t.name);
            return val;
        }
        default:
            std::cout << "error: " << t.kind << "\n";
            throw "error";
    }
}

double Interpreter::term() {
    double left = primary();
    Token t = ts.get();
    
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {    double d = primary();
                if (d == 0)
                    throw "error";
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double Interpreter::expression() {
    double left = term();
    Token t = ts.get();
    
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double Interpreter::declaration(){
    Token t = ts.get();
    if(t.kind != s_decl) {
        throw "error";
    }
    // variable name like 'x'
    std::string var_name = t.name;
    // must be '='
    Token t2 = ts.get();
    if(t2.kind != s_decl) {
        throw "error";
    }
    
    double d = expression();
    variable.define_name(var_name, d);
    return d;
}

double Interpreter::statement() {
    Token t = ts.get();
    switch (t.kind) {
        case s_set:
            return declaration();
            break;
        default:
            ts.putback(t);
            return expression();
            break;
    }
}

void Interpreter::calculate(){
    double response = 0;
    
    while (true) { // std::cin
        std::cout << s_prompt;
        // Read token through Token_Stream
        Token t = ts.get();
        
        if(t.kind == s_end){
            std::cout << s_result << response << '\n';
            std::cout << s_prompt;
        } else{
            ts.putback(t);
        }
        
        response = statement();
    }
}

