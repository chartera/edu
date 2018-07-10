#include <iostream>
#include <string>
#include <fstream>

struct Result {
  std::string status;
  std::fstream* fs;
  std::string info;
};

Result open_file(std::string fname) {
  std::fstream* fs = new std::fstream{fname};
  if(!fs) {
    return Result{"error", fs, "Can not open file"};
  }else{
    return Result{"ok", fs, "Open file successful"};
  }
};

Result write_to_file(std::fstream* cout, std::string content) {
  *cout << content;
  if(! *cout) {
    return Result{"error", cout, "Output operation error"};
  } else {  
    return Result{"ok", cout, "Output operation successful"};
  }
};


Result read_from_file(std::fstream* cin) {
  std::string read;
  *cin >> read;
  Result res;
  if(! *cin) {

    if(cin->bad())
      res = Result{"error", cin, "Fs is bad"};
    
    if(cin->fail())
      res =  Result{"error", cin, "Format error"};

    if(cin->eof())
      std::cout << read << '\n';
      res = Result{"ok", cin, "End of file"};

    return res;
    
  } else {
    std::cout << read << '\n';
    return Result{"ok", cin, "Read successful"};
  }
};

int main() {

  std::string fname = "/home/app/c/edu/io/src/bin/file.txt";

  // Open the file
  Result open_operation = open_file(fname);
  
  // Check status for opening the file
  if(open_operation.status == "ok"){ // Opening successful
    std::cout << open_operation.info << '\n';

    // Write to file
    Result write_operation =
      write_to_file(open_operation.fs, "HelloHelloHelloHello");
    std::cout << write_operation.info << '\n';

    // Check status for writing the file
    if(write_operation.status == "ok") { // writing successful

      // flush buffer
      open_operation.fs->flush();

      // Seek to 0 characters from the beginning of the file
      // because after write fs are at the end of the file
      open_operation.fs->seekg(0, std::ios::beg);
      
      Result read_operation =
	read_from_file(open_operation.fs);

      // fs is on the heap (created through new), free it
      // variables on the stack not needed that.
      // only object allocated by new needed to delete.
      delete open_operation.fs;
      
      std::cout << read_operation.info << '\n';
      
    }

  } else {

    std::cout << open_operation.info << '\n';
  }
  return 0;
}
