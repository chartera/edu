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
  double* elem;
public:
  
  Vector(int s): size{s}, elem{new double[s]}
  {
    for(int i = 0; i < s; i++) {
      // initialization for pointer
      elem[i] = i;
    }
  }

  ~Vector()
  {
    std::cout << "Destructor Vector \n";
    delete[] elem;
  }
  
  int get_size() const {return size;};
  double* get_elem() const {return elem;};

};

#endif /* vecotr_h */
