//
//  File.h
//  C++Edu
//
//  Created by Nael Tasmim on 11/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "descriptor.h"

class File{
  // std::vector<descriptor> descriptors;
public:

  File() {}
  
  descriptor open(std::string fname);
  descriptor write(std::fstream& cout, std::string content);
  descriptor read(std::fstream& cin);

  
};
