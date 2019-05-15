#include <unistd.h>
#include <stdio.h>

int main(int argc, char**argv) {
   printf("Executing %s ...\n", argv[1]);
   execvp( argv[1], argv + 1);
   printf("22222222\n");
   perror("Failed to be all powerful");
}
