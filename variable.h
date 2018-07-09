//
//  variable.hpp
//  C++Edu
//
//  Created by Nael Tasmim on 7/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#ifndef variable_hpp
#define variable_hpp

#include <string>

class Variable{
public:
    std::string name;
    double value;
    
    double define_name(std::string, double);
    double get_value(std::string);
};



#endif /* variable_hpp */
