//
//  variable.cpp
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#include "variable.h"
#include <string>
#include <vector>

std::vector<Variable> var_table;

double Variable::get_value(std::string s) {
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    throw 0;
}

void set_value(std::string s, double d) {
    for (Variable& v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
}

bool is_decalred(std::string var) {
    for(const Variable& v: var_table) {
        if(v.name == var) {
            return true;
        }
    }
    return false;
}

double Variable::define_name(std::string var, double val) {
    if(is_decalred(var)){
        throw "error";
    }
    Variable v = Variable{var, val};
    var_table.push_back(v);
    return val;
}

