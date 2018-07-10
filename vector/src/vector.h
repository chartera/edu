//
//  vector.h
//  C++Edu
//
//  Created by Nael Tasmim on 7/9/18.
//  Copyright © 2018 Nael Tasmim. All rights reserved.
//

#ifndef vector_h
#define vector_h

class Vector{
  int size;
  double* pointer;
public:

  Vector(int s): size{s}, pointer{new double[s]}
  {
    for(int i = 0; i < s; i++) {
      pointer[i] = i;
    }
  }

  ~Vector()
  {
    delete[] pointer;
  }
  
  int get_size() const {return size;};
  double* get_pointer() const {return pointer;};

};

#endif /* vecotr_h */
