#include <unistd.h>
#include <stdio.h>

int main() {
   execlp("cat", "cat", "execdemo.c" , (char*) 0);

   puts("Ooops exec failed!!");
   perror("Failed exec");
   return 0;
}

