//
//  File.h
//  C++Edu
//
//  Created by Nael Tasmim on 11/5/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#include "file.h"


descriptor File::open(std::string fname) {
  std::fstream* fs = new std::fstream{fname};
  if(!*fs) {

    return descriptor{"error", *fs, "Can not open file"};
  }else{
    return descriptor{"ok", *fs, "Open file successful"};
  }
};

descriptor File::write(std::fstream& cout, std::string content) {
  cout << content;
  if(! cout) {
    return descriptor{"error", cout, "Output operation error"};
  } else {  
    return descriptor{"ok", cout, "Output operation successful"};
  }
};

descriptor File::read(std::fstream& cin) {
  std::string read;
  cin >> read;
  descriptor res {"", cin, ""};
  if(! cin) { // Something went wrong with cin, opposite of good()

    if(cin.bad())
      res.status = "error";
      res.info = "Fs is bad";
    
    if(cin.fail())
      // Take out of the fail() state (good()) in order to be able to recover
      // and look at characters from it again
      cin.clear(); 
      res.status = "error";
      res.info = "Format error";
    

    if(cin.eof())
      cin.clear(); 
      res.status = "ok";
      res.info = "Read operatop end of file";
    

    return res;
    
  } else {
    std::cout << read << " ";
    return File::read(cin);
  }
};
