#include <iostream>
#include "vector.h"

int main() {

  int i = 4;
  // A pointer is an data type to holding an address of an specific data type
  int* ptri = &i;
  *ptri = 50; // assign 50 to &i (equal i = 50)
  
  double x = 3.3;
  double* ptrx = &x;
  *ptrx = *ptri; // assign &x to &i (equal x = i)  

  std::cout << "ptrx pointer to address = "
	    << ptrx << " ptrx value = " << *ptrx << '\n';


  // allocate four doubles (an array of 4 doubles) on the free store and return
  // a pointer to the first double.
  double* s = new double[4];
  // allocate one double
  double* t = new double;

  // In addition to using the dereference operator * on a pointer,
  // we can use the subscript operator [ ].
  // read the (first) object pointed to by s. (s[0] means *s)
  double n = *s; 
  // read the 3rd object pointed to by s. 
  double o = s[2];

  // the [] (subscript operator) and * (contents of operator or dereference operator)
  // cans also be used for writing
  // write to te (first) object pointed to by s
  *s= 20;
  // write to the 3rd object pointed to by s
  s[2] = 10;
  
  std::cout << "Test " << *s << '\n';

  // frees the memory for an array of objects allocated by new
  delete[] s;
  // frees the memory for an individual object allocated by new
  delete ptri; 
 
  std::cout << "Test " << *s << '\n';

  Vector vector{5};

  for(int index = 0; index < vector.get_size(); index++) {
    std::cout << "--- " << vector.get_pointer()[index] << '\n';
  }

  #
  
  return 0;
}
