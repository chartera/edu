#include <iostream>
#include "vector.h"
#include <vector>

std::vector<char>* fill_ptr(std::istream& cin) {
  std::string str;
  std::getline(cin, str);

  std::vector<char>* chars =
    new std::vector<char>(str.begin(), str.end());  
  
  return chars;
}

std::vector<char>& fill(std::istream& cin) {

  std::string str;
  std::getline(cin, str);
  /*
   * str.begin() returns an iterator 
   * pointing to the first character of the string. 
   * 
   * str.end() Returns an iterator pointing to the past-the-end 
   * character of the string.
   * 
   * Input iterators to the initial and final positions in a range. 
   */
  
  return *new std::vector<char>(str.begin(), str.end());
}

int main() {

  int i = 4;
  // A pointer is an data type to holding an address of an specific data type
  int* ptri = &i;
  *ptri = 50; // assign 50 to &i (equal i = 50)
  
  std::cout << "Pointer access with subscript operator " << ptri[0] << "\n";
  
  double x = 3.3;
  double* ptrx = &x;
  *ptrx = *ptri; // assign &x to &i (equal x = i)  

  std::cout << "ptrx pointer to address = "
	    << ptrx << " ptrx value = " << *ptrx << '\n';

  std::cout << "sizeof(char) is: " << sizeof(char) << "byte \n";

  int* ints = new int[4];
  ints[0] = 4;
  std::cout << "ints[0] " << ints[0] << "\n";
  
  int to = 1;
  int* to_address = &to;
  int temp = to_address[0];
  *to_address = 10;
  std::cout << "temp are: " << temp << "\n";
  std::cout << "to are: " << to << "\n";
 
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

  // automatic call of destructor when out of scope
  Vector vector{5};
  std::cout << "vector size : " << vector.get_size() << "\n";

  for(int index = 0; index < vector.get_size(); index++) {
    std::cout << "--- " << vector.get_elem()[index] << '\n';
  }

  Vector* v = new Vector{5};
  std::cout << "v size : " << v->get_size() << "\n";
  
  std::cout << "vector: " << &vector << "\n";
  std::cout << "v: " << &v << "\n";

  int z = 7;
  int* z_pointer = &z;
  *z_pointer = 9;

  std::cout << "z = " << z << "\n";

  int tol = 6;
  int& ref = tol;
  ref = 99;
  std::cout << "tol = " << 43 << "\n";
  
  std::cout << "Near out of scope \n";

  /*
  std::vector<char> vec = fill(std::cin);

  std::cout << "vec size before delete: " << vec.size()  << "\n";
  for(int i = 0; i < vec.size(); i++){
    std::cout << "word: " << vec.at(i)  << "\n";
  } 

  std::vector<char>* vec2 = &vec;
  
  delete &vec;

  std::cout << "vec size after delete: " << vec.size()  << "\n";
  std::cout << "vec2 size after delete: " << vec2->size()  << "\n";
  */


  // vector capacity

  
  std::vector<char> my_vec {'a', 'b'};
  my_vec.push_back('c');
  std::cout << "My vector capacity: " << my_vec.capacity()<< "\n";
  
  // c stlye string with arrays

  char* name = "Nael";

  int index = 0;
  std::cout << "Iterate over chars \n"; 
  while(name[index]) {
    std::cout << name[index] << "\n";
    index++;
  }
  
  // pointer arithmetic

  double ad[2];
  double* ad_pointer0 = &ad[0];
  double* ad_pointer1 = &ad[1];
  std::cout << "Pointer ad_pointer0 " << ad_pointer0 << "\n";
  std::cout << "Pointer ad_pointer1 " << ad_pointer1 << "\n";
  std::string check = ad_pointer1 > ad_pointer0 ? "true" : "false";
  std::cout << "ad_pointer1 > ad_pointer0: " << check << "\n";

  ad[0] = 1;
  ad[1] = 2;
  int count = 0;
  while(count < 2){
    std::cout << *ad_pointer0 << "\n";
    ++count;
    ++ad_pointer0;
  }
  std::cout << "ad count: " << count << "\n";
    
  
  // with pointers

  std::vector<char>* vec_ptr = fill_ptr(std::cin);
  std::cout << "vec_ptr size before delete: " << vec_ptr->size()  << "\n";
    std::vector<char>* move_vec_ptr = vec_ptr;
  delete vec_ptr;
  std::cout << "vec_ptr size after delete: " << vec_ptr->size()  << "\n";
  std::cout << "move_vec_ptr size after vec_ptr delete: "
	    << move_vec_ptr->size()  << "\n";
  
  return 0;
}
