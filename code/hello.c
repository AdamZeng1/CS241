#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv) {
  printf("Hello world using formatted printing %s %d %.3f","OK?",42,3.1415926);
  puts(" ... or just a string with an newline added");

  // Internally the above C library calls use 'write' to write bytes
  // to the actual standard output. So let's do that directly -

  write(1," !! Low level way to print stuff",15);
  // I guessed 15 bytes *might* be enough

  // Better quality code might use STDOUT_FILENO in place of "1"
  // and perhaps we should strlen or sizeof to calculate the 
  // number of bytes to write to the ouput
  return 0;
}
