#include "file.h"

int main() {

  std::string fname = "/home/app/c/edu/io/src/bin/file.txt";

  File file;
  
  // Open the file
  descriptor open_operation = file.open(fname);
  
  // Check status for opening the file
  if(open_operation.status == "ok"){ // Opening successful
    std::cout << "--" << open_operation.info << "--" << '\n';

    // Write to file
    descriptor write_operation =
      file.write(open_operation.fs, "Hello World");
    std::cout << "--" << write_operation.info << "--" << '\n';

    // Check status for writing the file
    if(write_operation.status == "ok") { // writing successful
      
      // flush buffer
      open_operation.fs.flush();

      // Seek to 0 characters from the beginning of the file
      // because after write fs are at the end of the file
      open_operation.fs.seekg(0, std::ios::beg);
      
      descriptor read_operation =
	file.read(open_operation.fs);

      // fs is on the heap (created through new), free it
      // variables on the stack not needed that.
      // only object allocated by new needed to delete.
      delete &open_operation;
      
      std::cout << '\n' << "--" << read_operation.info << "--" << '\n';
      
    }

  } else {

    std::cout << open_operation.info << '\n';
  }
  return 0;
}
