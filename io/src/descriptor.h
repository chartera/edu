//
//  descriptor.h
//  C++Edu
//
//  Created by Nael Tasmim on 11/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//


#ifndef descriptor_h
#define descriptor_h


struct descriptor {
  std::string status;
  std::fstream& fs;
  std::string info;

  ~descriptor() {
    delete &fs;
  };
};

#endif /* descriptor_h */
