
#include <stdio.h>

int main(int argc, char**argv) {

fprintf(stdout, "hello\n");  
fprintf(stderr, "CS 241: ");
fprintf(stdout, "System ");
fprintf(stderr, "Programming ");

return 0;
}
// a.out > hello.txt 2> error.log
// or just a.out for a surprise...
