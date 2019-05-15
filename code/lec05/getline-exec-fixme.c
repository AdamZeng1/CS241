#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
  char* line = NULL;
  size_t size =0;
  ssize_t bytesread = getline(&line, &size, stdin); 
  printf("We are about to run : '%s'", line);
  fflush(stdout);
  if(bytesread  > 1) {
    if(line[bytesread-1] == '\n') {
       line[bytesread-1] = '\0';
    }

    execlp(line, line, (char*) 0);
    perror("execlp failed!");
  }
  return 0; 
}
